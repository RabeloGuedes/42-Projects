#include <stddef.h>
#include <sys/types.h>

// Magic sentinel value to detect weak symbols
#define WEAK_SENTINEL 0xDEADBEEF

// Weak wrapper functions that allow linking even when libasm functions are missing
// These will be overridden by strong symbols from libasm.a if they exist
// They return sentinel values so we can detect if the real function was linked

size_t __attribute__((weak)) ft_strlen(const char *s)
{
	(void)s;
	return WEAK_SENTINEL;
}

char __attribute__((weak)) *ft_strcpy(char *dst, const char *src)
{
	(void)dst;
	(void)src;
	return (char *)WEAK_SENTINEL;
}

int __attribute__((weak)) ft_strcmp(const char *s1, const char *s2)
{
	(void)s1;
	(void)s2;
	return WEAK_SENTINEL;
}

ssize_t __attribute__((weak)) ft_write(int fd, const void *buf, size_t count)
{
	(void)fd;
	(void)buf;
	(void)count;
	return WEAK_SENTINEL;
}

ssize_t __attribute__((weak)) ft_read(int fd, void *buf, size_t count)
{
	(void)fd;
	(void)buf;
	(void)count;
	return WEAK_SENTINEL;
}

char __attribute__((weak)) *ft_strdup(const char *s)
{
	(void)s;
	return (char *)WEAK_SENTINEL;
}
