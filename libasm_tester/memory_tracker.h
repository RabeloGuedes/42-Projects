#ifndef MEMORY_TRACKER_H
# define MEMORY_TRACKER_H

# include <stdlib.h>

// Memory tracking statistics
typedef struct s_mem_stats
{
	int	allocations;
	int	frees;
	int	leaked_bytes;
	int	total_allocated;
}	t_mem_stats;

// Initialize memory tracking
void	mem_track_init(void);

// Track malloc/free calls
void*	mem_track_malloc(size_t size);
void	mem_track_free(void *ptr);

// Get statistics
t_mem_stats	mem_track_get_stats(void);

// Reset tracking
void	mem_track_reset(void);

// Check for leaks
int	mem_track_has_leaks(void);

#endif
