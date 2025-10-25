/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:31:28 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/07 14:21:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function checks if a given string
// is valid as a ascii number representation.
int	are_arg_num(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str && !ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// This function checks if a given string
// is valid as a ascii integer represatation,
// this means that it should be bewteen INT_MIN
// and INT_MAX, included.
int	a_is_int_range(const char *str)
{
	long long	nbr;

	nbr = ft_atoll(str);
	if (nbr < INT32_MIN || nbr > INT32_MAX)
		return (0);
	return (1);
}

// This function checks if any of the arguments
// is duplicated.
int	duplicates_checker(char **args)
{
	char	**save;

	while (*args)
	{
		save = args + 1;
		while (*save)
		{
			if (ft_atoi(*args) == ft_atoi(*save))
				return (0);
			save++;
		}
		args++;
	}
	return (1);
}
