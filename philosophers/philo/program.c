/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:13:00 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/06 14:49:03 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function initializes the program, returns true if succeed,
// otherwise returns false.
/// @param ac 
/// @param av 
/// @param program 
/// @param monitor 
/// @return 
bool	init_program(int ac, char **av, t_program *program, t_monitor *monitor)
{
	program->ac = ac;
	program->av = av;
	program->monitor = monitor;
	program->philos_amount = ft_atoul(*av);
	program->created_forks_mutexes = 0;
	if (!init_monitor(program, av))
		return (false);
	if (!init_forks(program, program->philos_amount))
		return (false);
	if (!init_philos(program))
		return (false);
	return (true);
}

/// @brief This function executes for each thread the join function,
// in case of success it reutrns true, otherwise false.
/// @param program 
/// @return 
bool	run_program(t_program *program)
{
	size_t	i;

	i = 0;
	while (i < program->philos_amount)
	{
		if (pthread_join(program->philos[i].thread, NULL))
		{
			free_project(program, FP_LEVEL_6, &pthread_join_error);
			return (false);
		}
		i++;
	}
	return (true);
}

/// @brief This function writes the given message in the terminal
// with the timestamp, and philosopher id.
/// @param philo 
/// @param str 
void	printf_msg(t_philo *philo, const char *str)
{
	pthread_mutex_lock(philo->printf_lock);
	pthread_mutex_lock(philo->timestamp_lock);
	if (!check_dead_flag(philo))
		printf("%li %li %s", timestamp() - philo->start_timestamp,
			philo->id, str);
	pthread_mutex_unlock(philo->timestamp_lock);
	pthread_mutex_unlock(philo->printf_lock);
}

/// @brief This function checks if any philosopher has died,
// returns false if everybody is alive or true if someone is dead.
/// @param philo 
/// @return 
bool	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_flag_lock);
	if (*philo->anyone_dead)
	{
		pthread_mutex_unlock(philo->dead_flag_lock);
		return (true);
	}
	pthread_mutex_unlock(philo->dead_flag_lock);
	return (false);
}

/// @brief This function initializes the threads, if it succeed returns true,
/// otherwise returns false.
/// @param philos 
/// @param forks 
/// @param philos_amount 
/// @return 
bool	init_threads(t_philo *philos, size_t philos_amount)
{
	size_t	i;

	i = 0;
	while (i < philos_amount)
	{
		if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]))
			return (false);
		i++;
	}
	return (true);
}
