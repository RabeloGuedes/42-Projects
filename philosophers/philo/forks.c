/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:49:16 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 10:05:27 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function allocates memory for all forks.
/// @param num_of_philos 
/// @return 
pthread_mutex_t	*create_forks(size_t num_of_philos)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!forks)
		return (NULL);
	return (forks);
}

/// @brief This function initializes all forks-mutexes,
// if the initialization fails it calls the mutex_error function,
// destroy all previously initialized mutexes and deallocates all forks.
/// @param program 
/// @param num_of_philos 
/// @return 
bool	init_forks(t_program *program, size_t num_of_philos)
{
	program->forks = create_forks(num_of_philos);
	if (!program->forks)
	{
		free_project(program, FP_LEVEL_4, &malloc_error);
		return (false);
	}
	while (program->created_forks_mutexes < num_of_philos)
	{
		if (pthread_mutex_init(
				&program->forks[program->created_forks_mutexes],
				NULL))
		{
			free_project(program, FP_LEVEL_5, &mutex_error);
			return (false);
		}
		program->created_forks_mutexes++;
	}
	return (true);
}
