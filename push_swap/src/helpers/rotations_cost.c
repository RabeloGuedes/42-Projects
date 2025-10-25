/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:16:45 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/19 16:20:32 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function calculates how many rotations a certain
// node needs to be inserted into the right spot in the,
// destination stack.
int	rotations_cost(t_list *searched_node, t_list *head_origin,
	t_list *head_dest, char order_type)
{
	int	origin_rotations;
	int	dest_rotations;

	origin_rotations = rotations_to_top(head_origin, searched_node);
	dest_rotations = right_position_at_dest(searched_node,
			head_dest, order_type);
	if (origin_rotations < 0 && dest_rotations < 0)
	{
		if (origin_rotations <= dest_rotations)
			return (ft_abs_value(origin_rotations));
		return (ft_abs_value(dest_rotations));
	}
	else if (origin_rotations > 0 && dest_rotations > 0)
	{
		if (origin_rotations >= dest_rotations)
			return (ft_abs_value(origin_rotations));
		return (ft_abs_value(dest_rotations));
	}
	return (ft_abs_value(origin_rotations) + ft_abs_value(dest_rotations));
}
