/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcalute_least_rotations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:13:14 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/19 16:20:00 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function calculates how many rotations
// are necessary to get a certain node to the
// top of the stack, if by rotating counterclockwise
// (forward/rotate) or by rotating clockwise
// (backward/reverse rotate).
int	rotations_to_top(t_list *head, t_list *searched_node)
{
	int	forward;
	int	backward;

	forward = 0;
	backward = 0;
	while (head != searched_node)
	{
		head = head->next;
		forward++;
	}
	while (searched_node)
	{
		searched_node = searched_node->next;
		backward++;
	}
	if (forward <= backward)
		return (forward);
	else
		return (-backward);
}

// This function calculates how many rotations
// are necessary to get a certain node to the
// bottom of the stack, if by rotating counterclockwise
// (forward/rotate) or by rotating clockwise
// (backward/reverse rotate).
int	rotations_to_bottom(t_list *head, t_list *searched_node)
{
	int	forward;
	int	backward;

	forward = 1;
	backward = 0;
	while (head != searched_node)
	{
		head = head->next;
		forward++;
	}
	while (searched_node->next)
	{
		searched_node = searched_node->next;
		backward++;
	}
	if (forward <= backward)
		return (forward);
	else
		return (-backward);
}

// This function calculates the position to
// insert a new node (number) into the right
// place on the destination stack, by checking
// where a greater number (node) and a smaller
// number (node) are located, in order to
// insert the new one bewteen both.
int	right_position_at_dest(t_list *new_node,
	t_list *head_dest, char postion_type)
{
	t_list		*max;
	t_list		*min;
	t_list		*correct_position;

	max = ft_lst_find_max(head_dest);
	min = ft_lst_find_min(head_dest);
	if ((*(int *)new_node->content > *(int *)max->content)
		|| (*(int *)new_node->content < *(int *)min->content))
	{
		if (postion_type == 'd')
			return (rotations_to_top(head_dest, max));
		else
			return (rotations_to_top(head_dest, min));
	}
	else
	{
		if (postion_type == 'd')
			correct_position = find_the_right_position_b(new_node, head_dest);
		else
			correct_position = find_the_right_position_a(new_node, head_dest);
		return (rotations_to_bottom(head_dest, correct_position));
	}
}
