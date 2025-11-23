#include "libtest.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

// External declaration - will be linked from libasm.a or weak wrapper
extern ssize_t ft_write(int fd, const void *buf, size_t count);

void test_ft_write(t_test_stats *stats)
{
	print_header("Testing ft_write");
	
	// Check if function is implemented (detect weak wrapper)
	if (ft_write(1, "test", 4) == (ssize_t)0xDEADBEEF)
	{
		printf("%s  Function not found%s\n", COLOR_YELLOW, COLOR_RESET);
		return;
	}
	
	// Test 1: Write to stdout
	{
		const char *test = "Test";
		ssize_t expected = write(STDOUT_FILENO, test, strlen(test));
		ssize_t result = ft_write(STDOUT_FILENO, test, strlen(test));
		int passed = (result == expected);
		print_test_result("Write to stdout", passed, 
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 2: Write empty string
	{
		const char *test = "";
		ssize_t expected = write(STDOUT_FILENO, test, 0);
		ssize_t result = ft_write(STDOUT_FILENO, test, 0);
		int passed = (result == expected);
		print_test_result("Write empty string", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 3: Write to file
	{
		const char *filename = "/tmp/test_ft_write.txt";
		const char *test = "Hello, World!";
		
		// Test with libc write
		int fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t expected = write(fd1, test, strlen(test));
		close(fd1);
		
		// Test with ft_write
		int fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t result = ft_write(fd2, test, strlen(test));
		close(fd2);
		
		int passed = (result == expected);
		unlink(filename);
		print_test_result("Write to file", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 4: Write long string
	{
		char test[1001];
		memset(test, 'A', 1000);
		test[1000] = '\0';
		
		const char *filename = "/tmp/test_ft_write_long.txt";
		int fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t expected = write(fd1, test, 1000);
		close(fd1);
		
		int fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t result = ft_write(fd2, test, 1000);
		close(fd2);
		
		int passed = (result == expected);
		unlink(filename);
		print_test_result("Write long string (1000 chars)", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 5: Write with count smaller than string length
	{
		const char *test = "HelloWorld";
		const char *filename = "/tmp/test_ft_write_partial.txt";
		
		int fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t expected = write(fd1, test, 5);
		close(fd1);
		
		int fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t result = ft_write(fd2, test, 5);
		close(fd2);
		
		int passed = (result == expected);
		unlink(filename);
		print_test_result("Write partial string (5 bytes)", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 6: Invalid file descriptor
	{
		const char *test = "Hello";
		errno = 0;
		ssize_t expected = write(-1, test, strlen(test));
		int expected_errno = errno;
		
		errno = 0;
		ssize_t result = ft_write(-1, test, strlen(test));
		int result_errno = errno;
		
		int passed = (result == expected && result == -1 && 
		              expected_errno == result_errno);
		char detail[200];
		if (!passed)
			snprintf(detail, sizeof(detail), 
				"Expected: %zd (errno %d), Got: %zd (errno %d)", 
				expected, expected_errno, result, result_errno);
		print_test_result("Invalid file descriptor (-1)", passed,
			passed ? "" : detail);
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 7: Write to stderr
	{
		const char *test = "Error message";
		ssize_t expected = write(STDERR_FILENO, test, strlen(test));
		ssize_t result = ft_write(STDERR_FILENO, test, strlen(test));
		int passed = (result == expected);
		print_test_result("Write to stderr", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 8: Write with special characters
	{
		const char *test = "Tab\tNewline\nReturn\rNull";
		const char *filename = "/tmp/test_ft_write_special.txt";
		
		int fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t expected = write(fd1, test, strlen(test));
		close(fd1);
		
		int fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t result = ft_write(fd2, test, strlen(test));
		close(fd2);
		
		int passed = (result == expected);
		unlink(filename);
		print_test_result("Write with special characters", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 9: Write binary data
	{
		unsigned char test[256];
		for (int i = 0; i < 256; i++)
			test[i] = (unsigned char)i;
		
		const char *filename = "/tmp/test_ft_write_binary.txt";
		int fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t expected = write(fd1, test, 256);
		close(fd1);
		
		int fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ssize_t result = ft_write(fd2, test, 256);
		close(fd2);
		
		int passed = (result == expected);
		unlink(filename);
		print_test_result("Write binary data (256 bytes)", passed,
			passed ? "" : "Return values don't match");
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 10: Write to closed file descriptor
	{
		const char *test = "Hello";
		const char *filename = "/tmp/test_ft_write_closed.txt";
		
		int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(fd);
		
		errno = 0;
		ssize_t expected = write(fd, test, strlen(test));
		int expected_errno = errno;
		
		errno = 0;
		ssize_t result = ft_write(fd, test, strlen(test));
		int result_errno = errno;
		
		int passed = (result == expected && result == -1 && 
		              expected_errno == result_errno);
		unlink(filename);
		char detail[200];
		if (!passed)
			snprintf(detail, sizeof(detail), 
				"Expected: %zd (errno %d), Got: %zd (errno %d)", 
				expected, expected_errno, result, result_errno);
		print_test_result("Write to closed file descriptor", passed,
			passed ? "" : detail);
		stats->total++;
		if (passed) stats->passed++;
		else stats->failed++;
	}
	
	// Test 11: NULL buffer (must segfault like libc)
	{
		// Use volatile to prevent compiler from detecting NULL at compile time
		volatile void *null_ptr = NULL;
		
		pid_t pid = fork();
		if (pid == 0)
		{
			// Child process - test ft_write
			ft_write(STDOUT_FILENO, (const void *)null_ptr, 10);
			exit(0);
		}
		else if (pid > 0)
		{
			// Parent process
			int status;
			waitpid(pid, &status, 0);
			int ft_segfaulted = WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV;
			
			// Test libc write
			pid = fork();
			if (pid == 0)
			{
				write(STDOUT_FILENO, (const void *)null_ptr, 10);
				exit(0);
			}
			else if (pid > 0)
			{
				waitpid(pid, &status, 0);
				int libc_segfaulted = WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV;
				
				int passed = (ft_segfaulted == libc_segfaulted);
				char detail[200];
				if (!passed)
				{
					if (!ft_segfaulted && libc_segfaulted)
						snprintf(detail, sizeof(detail), 
							"ft_write did not segfault on NULL buffer");
				else
					snprintf(detail, sizeof(detail), 
						"ft_write segfaulted but libc write did not");
			}
			print_test_result("NULL buffer (must segfault like libc)", 
				passed, passed ? "" : detail);
			stats->total++;
			if (passed) stats->passed++;
			else stats->failed++;
		}
	}
}

	printf("\n");
}