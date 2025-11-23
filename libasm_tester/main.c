#include "libtest.h"
#include <unistd.h>

// Global flag for verbose mode
int g_verbose_mode = 0;
static int g_is_tty = 0;

int main(int argc, char **argv)
{
	char libasm_path[1024];
	t_test_stats stats = {0, 0, 0};
	t_test_stats mandatory_stats = {0, 0, 0};
	t_test_stats bonus_stats = {0, 0, 0};
	
	// Check if stdout is a terminal
	g_is_tty = isatty(STDOUT_FILENO);
	
	// Print welcome message
	printf("\n%s", COLOR_MAGENTA);
	printf("╔════════════════════════════════════════════════════════════╗\n");
	printf("║                                                            ║\n");
	printf("║              LIBASM COMPREHENSIVE TEST SUITE               ║\n");
	printf("║                                                            ║\n");
	printf("╚════════════════════════════════════════════════════════════╝\n");
	printf("%s\n", COLOR_RESET);
	
	// Check for verbose flag
	int path_arg_index = 1;
	if (argc >= 2 && strcmp(argv[1], "-v") == 0)
	{
		g_verbose_mode = 1;
		path_arg_index = 2;
	}
	
	// Check if path was provided as argument
	if (argc >= path_arg_index + 1)
	{
		strncpy(libasm_path, argv[path_arg_index], sizeof(libasm_path) - 1);
		libasm_path[sizeof(libasm_path) - 1] = '\0';
		if (g_verbose_mode)
			printf("%sUsing libasm path from argument: %s%s\n", 
				COLOR_CYAN, libasm_path, COLOR_RESET);
	}
	else
	{
		// Prompt for libasm path
		printf("%sEnter the path to your libasm project: %s", 
			COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
		
		if (fgets(libasm_path, sizeof(libasm_path), stdin) == NULL)
		{
			printf("%sError: Failed to read path%s\n", COLOR_RED, COLOR_RESET);
			return 1;
		}
		
		// Remove trailing newline
		size_t len = strlen(libasm_path);
		if (len > 0 && libasm_path[len - 1] == '\n')
			libasm_path[len - 1] = '\0';
	}
	
	// Validate path
	if (strlen(libasm_path) == 0)
	{
		printf("%sError: Empty path provided%s\n", COLOR_RED, COLOR_RESET);
		return 1;
	}
	
	// Build libasm
	printf("\n%sBuilding libasm...%s\n", COLOR_YELLOW, COLOR_RESET);
	char make_cmd[2048];
	snprintf(make_cmd, sizeof(make_cmd), "make -C %s 2>&1", libasm_path);
	
	int make_result = system(make_cmd);
	if (make_result != 0)
	{
		printf("%sWarning: make returned non-zero status. Continuing anyway...%s\n", 
			COLOR_YELLOW, COLOR_RESET);
	}
	else
	{
		printf("%sLibasm built successfully!%s\n", COLOR_GREEN, COLOR_RESET);
	}
	
	// Validate libasm.a exists
	char lib_file[2048];
	snprintf(lib_file, sizeof(lib_file), "%s/libasm.a", libasm_path);
	FILE *f = fopen(lib_file, "r");
	if (!f)
	{
		printf("%sError: libasm.a not found at %s%s\n", 
			COLOR_RED, lib_file, COLOR_RESET);
		printf("%sPlease make sure your libasm project builds correctly.%s\n",
			COLOR_YELLOW, COLOR_RESET);
		return 1;
	}
	fclose(f);
	
	if (g_verbose_mode)
		printf("%sFound libasm.a at %s%s\n\n", COLOR_GREEN, lib_file, COLOR_RESET);
	
	// Run tests
	if (g_verbose_mode)
	{
		printf("%s════════════════════════════════════════════════════════════%s\n", 
			COLOR_CYAN, COLOR_RESET);
		printf("%s                    MANDATORY FUNCTIONS                     %s\n", 
			COLOR_WHITE, COLOR_RESET);
		printf("%s════════════════════════════════════════════════════════════%s\n\n", 
			COLOR_CYAN, COLOR_RESET);
	}
	else
	{
		printf("\n");
	}
	
	// Test mandatory functions
	test_ft_strlen(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░] 17%% (1/6)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_strcpy(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [███████████████░░░░░░░░░░░░░░░░░░░░░░░░░░] 33%% (2/6)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_strcmp(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [██████████████████████░░░░░░░░░░░░░░░░░░░] 50%% (3/6)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_write(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [█████████████████████████████░░░░░░░░░░░░] 67%% (4/6)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_read(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [████████████████████████████████████░░░░░░] 83%% (5/6)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_strdup(&mandatory_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Mandatory Functions:%s [█████████████████████████████████████████] 100%% (6/6)", COLOR_CYAN, COLOR_RESET);
		else
			printf("%sTesting Mandatory Functions:%s [█████████████████████████████████████████] 100%% (6/6)", COLOR_CYAN, COLOR_RESET);
		printf("\n");
		fflush(stdout);
	}
	
	// Calculate mandatory completion
	int mandatory_complete = (mandatory_stats.failed == 0 && mandatory_stats.total > 0);
	
	if (g_verbose_mode)
	{
		printf("%s════════════════════════════════════════════════════════════%s\n", 
			COLOR_CYAN, COLOR_RESET);
		printf("%s                     BONUS FUNCTIONS                        %s\n", 
			COLOR_WHITE, COLOR_RESET);
		printf("%s════════════════════════════════════════════════════════════%s\n\n", 
			COLOR_CYAN, COLOR_RESET);
	}
	else
	{
		printf("\n");
	}
	
	// Test bonus functions
	test_ft_atoi_base(&bonus_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Bonus Functions:%s [████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░] 20%% (1/5)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_list_push_front(&bonus_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Bonus Functions:%s [████████████████░░░░░░░░░░░░░░░░░░░░░░░░░] 40%% (2/5)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_list_size(&bonus_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Bonus Functions:%s [████████████████████████░░░░░░░░░░░░░░░░░] 60%% (3/5)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_list_sort(&bonus_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Bonus Functions:%s [████████████████████████████████░░░░░░░░░] 80%% (4/5)", COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
	}
		
	test_ft_list_remove_if(&bonus_stats);
	if (!g_verbose_mode)
	{
		if (g_is_tty)
			printf("\r\033[2K%sTesting Bonus Functions:%s [█████████████████████████████████████████] 100%% (5/5)", COLOR_CYAN, COLOR_RESET);
		else
			printf("%sTesting Bonus Functions:%s [█████████████████████████████████████████] 100%% (5/5)", COLOR_CYAN, COLOR_RESET);
		printf("\n");
		fflush(stdout);
	}
	
	// Combine stats for summary
	stats.total = mandatory_stats.total + bonus_stats.total;
	stats.passed = mandatory_stats.passed + bonus_stats.passed;
	stats.failed = mandatory_stats.failed + bonus_stats.failed;
	
	// Print final summary
	if (g_verbose_mode)
	{
		print_summary(stats);
	}
	else
	{
		// Print progress bar summary
		printf("\n%s════════════════════════════════════════════════════════════%s\n", 
			COLOR_CYAN, COLOR_RESET);
		printf("%s                         FINAL SCORE                        %s\n", 
			COLOR_WHITE, COLOR_RESET);
		printf("%s════════════════════════════════════════════════════════════%s\n\n", 
			COLOR_CYAN, COLOR_RESET);
		
		// Calculate score
		float mandatory_score = 0;
		float bonus_score = 0;
		
		if (mandatory_stats.total > 0)
		{
			mandatory_score = (float)mandatory_stats.passed / mandatory_stats.total * 100.0;
		}
		
		// Bonus only counts if mandatory is 100%
		if (mandatory_complete && bonus_stats.total > 0)
		{
			bonus_score = (float)bonus_stats.passed / bonus_stats.total * 25.0;
		}
		
		float total_score = mandatory_score + bonus_score;
		
		// Print results
		printf("  %sMandatory Tests:%s %d/%d passed (%.1f%%)\n",
			COLOR_WHITE, COLOR_RESET,
			mandatory_stats.passed, mandatory_stats.total, mandatory_score);
			
		if (bonus_stats.total > 0)
		{
			printf("  %sBonus Tests:%s     %d/%d passed ",
				COLOR_WHITE, COLOR_RESET,
				bonus_stats.passed, bonus_stats.total);
			
			if (mandatory_complete)
				printf("(+%.1f%%)\n", bonus_score);
			else
				printf("%s(not counted - mandatory incomplete)%s\n", 
					COLOR_YELLOW, COLOR_RESET);
		}
		
		printf("\n  %sFinal Score: ", COLOR_WHITE);
		if (total_score >= 100.0)
			printf("%s%.1f%%%s", COLOR_GREEN, total_score, COLOR_RESET);
		else if (total_score >= 80.0)
			printf("%s%.1f%%%s", COLOR_YELLOW, total_score, COLOR_RESET);
		else
			printf("%s%.1f%%%s", COLOR_RED, total_score, COLOR_RESET);
		printf(" / 125%%\n\n");
		
		// Progress bar
		int bar_width = 50;
		int filled = (int)(total_score / 125.0 * bar_width);
		if (filled > bar_width) filled = bar_width;
		
		printf("  [");
		for (int i = 0; i < bar_width; i++)
		{
			if (i < filled)
				printf("%s█%s", COLOR_GREEN, COLOR_RESET);
			else
				printf("░");
		}
		printf("]\n\n");
		
		if (mandatory_complete && total_score >= 100.0)
			printf("%s  ✓ All tests passed! Excellent work!%s\n\n", 
				COLOR_GREEN, COLOR_RESET);
		else if (mandatory_complete)
			printf("%s  ✓ Mandatory complete! Check bonus functions.%s\n\n", 
				COLOR_GREEN, COLOR_RESET);
		else if (mandatory_stats.failed > 0)
			printf("%s  ✗ Some mandatory tests failed.%s\n\n", 
				COLOR_RED, COLOR_RESET);
	}
	
	return (stats.failed > 0) ? 1 : 0;
}


