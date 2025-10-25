/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 19:27:46 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief  This function initializes the monitor struct
/// @param program 
/// @param av 
/// @return 
bool	init_monitor(t_program *program, char **av)
{
	program->monitor->anyone_dead = false;
	if (!init_monitor_1(program))
		return (false);
	if (!init_monitor_2(program))
		return (false);
	if (*(av + 4))
		program->monitor->num_least_meals = ft_atoul(*(av + 4));
	else
		program->monitor->num_least_meals = -1;
	program->monitor->philos_amount = program->philos_amount;
	return (true);
}

/// @brief This function is the first part of the init_monitor function.
/// @param program 
/// @return 
bool	init_monitor_1(t_program *program)
{
	if (pthread_mutex_init(&program->monitor->dead_flag_lock, NULL))
	{
		free_project(program, FP_LEVEL_0, &mutex_error);
		return (false);
	}
	if (pthread_mutex_init(&program->monitor->meals_flag_lock, NULL))
	{
		free_project(program, FP_LEVEL_1, &mutex_error);
		return (false);
	}
	return (true);
}

/// @brief This function is the second part of the init_monitor function.
/// @param program 
/// @return 
bool	init_monitor_2(t_program *program)
{
	if (pthread_mutex_init(&program->monitor->printf_lock, NULL))
	{
		free_project(program, FP_LEVEL_2, &mutex_error);
		return (false);
	}
	if (pthread_mutex_init(&program->monitor->timestamp_lock, NULL))
	{
		free_project(program, FP_LEVEL_3, &mutex_error);
		return (false);
	}
	return (true);
}
