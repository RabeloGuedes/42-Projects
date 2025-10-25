/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:45:05 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 19:21:11 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function checks if the philosopher still alive
// and returns false if not or true otherwise.
/// @param philo 
/// @return 
bool	check_if_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_flag_lock);
	pthread_mutex_lock(philo->timestamp_lock);
	if (timestamp() - philo->last_meal_timestamp
		>= philo->time_to_die_ms && !philo->eating)
	{
		pthread_mutex_unlock(philo->timestamp_lock);
		pthread_mutex_unlock(&philo->meals_flag_lock);
		return (false);
	}
	pthread_mutex_unlock(philo->timestamp_lock);
	pthread_mutex_unlock(&philo->meals_flag_lock);
	return (true);
}

/// @brief This function checks if any philosopher has died.
// In case anyone has died it writes a message with the timestamp and
// id of the philosopher changing the value of anyone_dead to true.
// Returns false if all philosophers still alive, otherwise true.
/// @param philos 
/// @return 
bool	is_anyone_dead(t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < philos[0].philos_amount)
	{
		if (!check_if_alive(&philos[i]))
		{
			printf_msg(&philos[i], DIED);
			pthread_mutex_lock(philos[i].dead_flag_lock);
			*philos[i].anyone_dead = true;
			pthread_mutex_unlock(philos[i].dead_flag_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

/// @brief This function checks if the philosopher had 
// the minimum number of meals in case it was given.
// Returns true if it had or if it has not set, otherwise false.
/// @param philo 
/// @param monitor 
/// @return 
bool	enough_meals_checker(t_philo *philo, t_monitor *monitor)
{
	pthread_mutex_lock(&philo->meals_flag_lock);
	if (philo->num_meals >= (size_t)monitor->num_least_meals)
	{
		pthread_mutex_unlock(&philo->meals_flag_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->meals_flag_lock);
	return (false);
}

/// @brief This function checks whether all philosophers have had the minimum
// number of meals they should. It returns true if they have and false
// if they have not.
/// @param monitor 
/// @param philos 
/// @return 
bool	is_everybody_satisfied(t_monitor *monitor, t_philo *philos)
{
	size_t	i;
	size_t	statisfied_philos;

	i = 0;
	statisfied_philos = 0;
	if (monitor->num_least_meals == -1)
		return (false);
	while (i < monitor->philos_amount)
	{
		if (enough_meals_checker(&philos[i], monitor))
			statisfied_philos++;
		i++;
	}
	if (monitor->philos_amount == statisfied_philos)
	{
		pthread_mutex_lock(&monitor->dead_flag_lock);
		monitor->anyone_dead = true;
		pthread_mutex_unlock(&monitor->dead_flag_lock);
		return (true);
	}
	return (false);
}

/// @brief This function monitors the philosophers until
// someone dies or all philosophers are satisfied.
/// @param moni 
/// @return 
void	*monitor_routine(void *moni)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)moni;
	while (!is_everybody_satisfied(monitor, monitor->philos)
		&& !is_anyone_dead(monitor->philos))
		usleep(500);
	return (monitor);
}
