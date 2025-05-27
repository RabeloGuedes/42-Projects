#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	*__real_malloc(size_t n);

void	*__wrap_malloc(size_t n)
{
	static int	seed;

	if (!seed)
	{
		seed = 1;
		srand(time(NULL));
	}
	if (rand() % 5 == 0)
	{
		printf("fake malloc\n");
		return (NULL);
	}
	printf("original malloc\n");
	return (__real_malloc(n));
}
