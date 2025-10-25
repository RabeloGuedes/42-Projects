/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:52:49 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 14:08:57 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function iterates over a stack from a
// certain node, assuming it is the head, and
// returns the node, which content is the highest. 
t_list	*ft_lst_find_max(t_list *head)
{
	t_list	*max_node;

	if (!head)
		return (NULL);
	max_node = head;
	while (head)
	{
		if (*(int *)head->content > *(int *)max_node->content)
			max_node = head;
		head = head->next;
	}
	return (max_node);
}

// This function iterates over a stack from a
// certain node, assuming it is the head, and
// returns the node, which content is the lowest.
t_list	*ft_lst_find_min(t_list *head)
{
	t_list	*min_node;

	if (!head)
		return (NULL);
	min_node = head;
	while (head)
	{
		if (*(int *)head->content < *(int *)min_node->content)
			min_node = head;
		head = head->next;
	}
	return (min_node);
}

// This function iterates over a stack from a
// certain node, assuming it is the head, and
// returns the node, which represents the correct
// position for a new node (number) when pushing
// from stack A to stack B and it should order it
// in descending order. 
t_list	*find_the_right_position_b(t_list *new_node, t_list *head_dest)
{
	int		new_node_content;
	int		head_dest_value;
	t_list	*save_head;

	if (!head_dest)
		return (NULL);
	new_node_content = *(int *)new_node->content;
	save_head = head_dest;
	while (head_dest)
	{
		head_dest_value = *(int *)head_dest->content;
		if (!head_dest->next && is_ascending(new_node_content, head_dest_value)
			&& is_descending(new_node_content, *(int *)save_head->content))
			return (head_dest);
		else if (head_dest->next
			&& is_ascending(new_node_content, head_dest_value)
			&& is_descending(new_node_content,
				*(int *)head_dest->next->content))
			return (head_dest);
		head_dest = head_dest->next;
	}
	return (NULL);
}

// This function iterates over a stack from a
// certain node, assuming it is the head, and
// returns the node, which represents the correct
// position for a new node (number) when pushing
// from stack B to stack A and it should order it
// in ascending order.
t_list	*find_the_right_position_a(t_list *new_node, t_list *head_dest)
{
	int		new_node_content;
	int		head_dest_value;
	t_list	*save_head;

	if (!head_dest)
		return (NULL);
	new_node_content = *(int *)new_node->content;
	save_head = head_dest;
	while (head_dest)
	{
		head_dest_value = *(int *)head_dest->content;
		if (!head_dest->next && is_descending(new_node_content, head_dest_value)
			&& is_ascending(new_node_content, *(int *)save_head->content))
			return (head_dest);
		else if (head_dest->next
			&& is_descending(new_node_content, head_dest_value)
			&& is_ascending(new_node_content,
				*(int *)head_dest->next->content))
			return (head_dest);
		head_dest = head_dest->next;
	}
	return (NULL);
}

// This function calculates which node needs
// the least amount of movements to get into
// the right position of the destination stack
// from the origin stack and returns it.
t_list	*find_cheapest(t_list *head_dest, t_list *head_origin, char order_type)
{
	t_list	*cheapest;
	t_list	*save_origin_top;
	int		cheapest_total_rotations;
	int		curr_total_rotations;

	cheapest = head_origin;
	save_origin_top = head_origin;
	cheapest_total_rotations = rotations_cost(cheapest, head_origin,
			head_dest, order_type);
	head_origin = head_origin->next;
	while (head_origin)
	{
		curr_total_rotations = rotations_cost(head_origin,
				save_origin_top, head_dest, order_type);
		if (cheapest_total_rotations > curr_total_rotations)
		{
			cheapest = head_origin;
			cheapest_total_rotations = curr_total_rotations;
		}
		head_origin = head_origin->next;
	}
	return (cheapest);
}
