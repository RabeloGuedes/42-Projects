/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:46 by arabelo-          #+#    #+#             */
/*   Updated: 2023/10/31 11:11:38 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_check_base(char *base)
{
	char	*copy;

	while (*base)
	{
		copy = base + 1;
		if (*base == '+' || *base == '-' || ft_isspace(*base))
			return (0);
		while (*copy)
		{
			if (*base == *copy)
				return (0);
			copy++;
		}
		base++;
	}
	return (1);
}
