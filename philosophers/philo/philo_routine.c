/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:40:22 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/06 16:31:22 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function makes half of the philosophers sleep and
// the other half execute straitforward all routines.
/// @param phi 
/// @return 
void	*philo_routine(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	if (philo->id % 2 == 0 || (philo->philos_amount % 2 != 0
			&& philo->id == philo->philos_amount))
	{
		go_think(philo);
		uwait(1);
	}
	while (!check_dead_flag(philo))
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (phi);
}
