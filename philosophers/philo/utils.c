/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:49:53 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/06 15:12:31 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/// @brief This function convert a string representation of
// a number into a unsigned long and returns it.
/// @param str 
/// @return
size_t	ft_atoul(const char *str)
{
	size_t	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - 48);
	return (res);
}

/// @brief This function pause the process for the amount of milliseconds
// given as parameter.
/// @param milliseconds 
void	uwait(size_t milliseconds)
{
	struct timeval	start;
	struct timeval	curr;
	size_t			elapsed;
	size_t			end;

	if (gettimeofday(&start, NULL) == -1)
		gettimeofday_error();
	end = (start.tv_sec * 1000 + start.tv_usec / 1000) + milliseconds; 
	while (1)
	{
		if (gettimeofday(&curr, NULL) == -1)
			gettimeofday_error();
		elapsed = curr.tv_sec * 1000 + curr.tv_usec / 1000;
		if (elapsed >= end)
			return ;
		usleep(100);
	}
}

/// @brief This function calculates and returns the timestamp in milliseconds.
/// @param  
/// @return 
size_t	timestamp(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		gettimeofday_error();
	return (now.tv_sec * MILLISECONDS_IN_A_SECOND
		+ now.tv_usec / MICROSECONDS_IN_A_MILLISECOND);
}

/// @brief This function returns the absolute value given as parameter.
/// @param value 
/// @return 
long	abs_value(long value)
{
	if (value < 0)
		return (-value);
	return (value);
}
