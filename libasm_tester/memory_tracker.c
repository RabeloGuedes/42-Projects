#include "memory_tracker.h"
#include <string.h>
#include <stdio.h>

#define MAX_ALLOCATIONS 10000

typedef struct s_alloc_entry
{
	void	*ptr;
	size_t	size;
	int		active;
}	t_alloc_entry;

static t_alloc_entry g_allocations[MAX_ALLOCATIONS];
static t_mem_stats g_stats = {0, 0, 0, 0};
static int g_initialized = 0;

void mem_track_init(void)
{
	memset(g_allocations, 0, sizeof(g_allocations));
	g_stats.allocations = 0;
	g_stats.frees = 0;
	g_stats.leaked_bytes = 0;
	g_stats.total_allocated = 0;
	g_initialized = 1;
}

void *mem_track_malloc(size_t size)
{
	void *ptr = malloc(size);
	
	if (!g_initialized)
		mem_track_init();
	
	if (ptr)
	{
		// Find free slot
		for (int i = 0; i < MAX_ALLOCATIONS; i++)
		{
			if (!g_allocations[i].active)
			{
				g_allocations[i].ptr = ptr;
				g_allocations[i].size = size;
				g_allocations[i].active = 1;
				g_stats.allocations++;
				g_stats.total_allocated += size;
				break;
			}
		}
	}
	
	return ptr;
}

void mem_track_free(void *ptr)
{
	if (!ptr)
		return;
	
	if (!g_initialized)
		mem_track_init();
	
	// Find and mark as freed
	for (int i = 0; i < MAX_ALLOCATIONS; i++)
	{
		if (g_allocations[i].active && g_allocations[i].ptr == ptr)
		{
			g_allocations[i].active = 0;
			g_stats.frees++;
			free(ptr);
			return;
		}
	}
	
	// Not tracked, just free it
	free(ptr);
}

t_mem_stats mem_track_get_stats(void)
{
	if (!g_initialized)
		mem_track_init();
	
	// Calculate current leaks
	g_stats.leaked_bytes = 0;
	for (int i = 0; i < MAX_ALLOCATIONS; i++)
	{
		if (g_allocations[i].active)
			g_stats.leaked_bytes += g_allocations[i].size;
	}
	
	return g_stats;
}

void mem_track_reset(void)
{
	mem_track_init();
}

int mem_track_has_leaks(void)
{
	if (!g_initialized)
		return 0;
	
	for (int i = 0; i < MAX_ALLOCATIONS; i++)
	{
		if (g_allocations[i].active)
			return 1;
	}
	
	return 0;
}
