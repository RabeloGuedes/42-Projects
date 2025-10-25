/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:59:05 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 10:04:32 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function destroys all initialized mutexes.
/// @param mutex 
/// @param num_of_mutexes 
void	destroy_mutexes(pthread_mutex_t *mutex, size_t num_of_mutexes)
{
	size_t	i;

	i = 0;
	while (mutex && i < num_of_mutexes)
	{
		if (pthread_mutex_destroy(&mutex[i++]))
			mutex_destroy_error();
	}
}

/// @brief Destroys all mutexes from monitor.
/// @param monitor 
void	destroy_monitor(t_monitor *monitor, size_t level)
{
	if (level >= 1)
		destroy_mutexes(&monitor->dead_flag_lock, 1);
	if (level >= 2)
		destroy_mutexes(&monitor->meals_flag_lock, 1);
	if (level >= 3)
		destroy_mutexes(&monitor->printf_lock, 1);
	if (level >= 4)
		destroy_mutexes(&monitor->timestamp_lock, 1);
}

/// @brief  This function deallocates all the memory previously allocated.
/// @param monitor 
/// @param philos 
/// @param forks
void	free_project(t_program *program,
	size_t level, void (*call_back_fn)(void))
{
	if (call_back_fn)
		call_back_fn();
	if (level == 1)
		destroy_monitor(program->monitor, 1);
	else if (level == 2)
		destroy_monitor(program->monitor, 2);
	else if (level == 3)
		destroy_monitor(program->monitor, 3);
	else if (level == 4)
		destroy_monitor(program->monitor, 4);
	if (level >= 5)
	{
		destroy_monitor(program->monitor, 4);
		destroy_mutexes(program->forks, program->created_forks_mutexes);
		free(program->forks);
	}
	if (level >= 6)
		free(program->philos);
}
