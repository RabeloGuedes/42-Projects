/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:43:41 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/14 13:16:33 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_num(int c)
{
	return (c >= '0' && c <= '9');
}

/// @brief  This function checks if a given string is only numeric.
/// @param str 
/// @return 
bool	is_param_valid(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' || str[0] == '+')
		{
			signed_param_error();
			return (false);
		}
		if (!is_num(str[i]))
		{
			no_num_param_error();
			return (false);
		}
		i++;
	}
	return (true);
}

/// @brief  This function checks if all parameters are valid.
/// @param av 
/// @return 
bool	check_all_params(char **av)
{
	if (!ft_atoul(*av))
	{
		no_philo_error();
		return (false);
	}
	while (*av)
	{
		if (!is_param_valid(*av))
			return (false);
		av++;
	}
	return (true);
}
