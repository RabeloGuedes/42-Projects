/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:03:11 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/07 14:20:04 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_swap(char *str)
{
	if (ft_strlen(str) != 3)
		return (0);
	if (str[0] != 's')
		return (0);
	if (str[1] != 'a' && str[1] != 'b' && str[1] != 's')
		return (0);
	if (str[2] != '\n')
		return (0);
	return (1);
}

int	is_rotation(char *str)
{
	if (ft_strlen(str) != 3)
		return (0);
	if (str[0] != 'r')
		return (0);
	if (str[1] != 'a' && str[1] != 'b' && str[1] != 'r')
		return (0);
	if (str[2] != '\n')
		return (0);
	return (1);
}

int	is_reverse_rotation(char *str)
{
	if (ft_strlen(str) != 4)
		return (0);
	if (str[0] != 'r')
		return (0);
	if (str[1] != 'r')
		return (0);
	if (str[2] != 'a' && str[2] != 'b' && str[2] != 'r')
		return (0);
	if (str[3] != '\n')
		return (0);
	return (1);
}

int	is_push(char *str)
{
	if (ft_strlen(str) != 3)
		return (0);
	if (str[0] != 'p')
		return (0);
	if (str[1] != 'a' && str[1] != 'b')
		return (0);
	if (str[2] != '\n')
		return (0);
	return (1);
}

int	movement_checker(char *str)
{
	if (ft_strlen(str) > 4 || ft_strlen(str) < 3)
		return (0);
	if (!is_swap(str) && !is_rotation(str)
		&& !is_reverse_rotation(str) && !is_push(str))
		return (0);
	return (1);
}
