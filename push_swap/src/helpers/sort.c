/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:43:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/07 14:21:33 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function is the first part of handle_up_to_3
// function, it checks if a simple rotate orders the
// stack, in this case it executes the rotate operation.
void	handle_simple_rotate_up_to_3(t_list **head)
{
	if (ft_lstsize(*head) == 3)
	{
		if (is_ascending(*(int *)(*head)->next->content,
			*(int *)(*head)->next->next->content)
			&& *head == ft_lst_find_max(*head))
			rotate(head, 'a');
	}
}

// This function is used to sort
// up to 3 node in a stack.
void	handle_up_to_3(t_list **head)
{
	handle_simple_rotate_up_to_3(head);
	while (!is_ordered(*head, &is_ascending))
	{
		if (!is_ascending(*(int *)(*head)->content,
			*(int *)ft_lstlast(*head)->content))
		{
			if ((*head)->next->next
				&& !is_ascending(*(int *)(*head)->content,
				*(int *)(*head)->next->content))
				swap(head, 'a');
			reverse_rotate(head, 'a');
		}
		else
		{
			if (is_ascending(*(int *)(*head)->content,
				*(int *)(*head)->next->content)
				&& !is_ascending(*(int *)(*head)->next->content,
				*(int *)ft_lstlast(*head)->content))
				reverse_rotate(head, 'a');
			swap(head, 'a');
		}
	}
}

// This function is the first part of the sort_bigger_stack
// function, it orders the numbers of stack A into the stack B
// in descending order, always calculating which node needs less
// movements to be placed in the correct position, until the stack
// A has only 3 nodes.
void	sort_in_descendig_to_b(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;
	int		origin_rotations;
	int		dest_rotations;

	while (ft_lstsize(*head_a) > 3)
	{
		cheapest = find_cheapest(*head_b, *head_a, 'd');
		origin_rotations = rotations_to_top(*head_a, cheapest);
		dest_rotations = right_position_at_dest(cheapest, *head_b, 'd');
		if (origin_rotations > 0 && dest_rotations > 0)
			handle_rotation_a(head_a, head_b, 'd');
		else if (origin_rotations < 0 && dest_rotations < 0)
			handle_reverse_rotation_a(head_a, head_b, 'd');
		else
			handle_opposite_direction_a(head_a, head_b, 'd');
		push(head_b, head_a, 'b');
	}
}

// This function is the second part of the sort_bigger_stack
// function, it orders the numbers of stack B into the stack A
// in ascending order, always calculating which node needs less
// movements to be placed in the correct position, this function
// is executed after handle_up_to_3.
void	sort_in_ascendig_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;
	int		origin_rotations;
	int		dest_rotations;

	while (ft_lstsize(*head_b))
	{
		cheapest = find_cheapest(*head_a, *head_b, 'a');
		origin_rotations = rotations_to_top(*head_b, cheapest);
		dest_rotations = right_position_at_dest(cheapest, *head_a, 'a');
		if (origin_rotations > 0 && dest_rotations > 0)
			handle_rotation_b(head_b, head_a, 'a');
		else if (origin_rotations < 0 && dest_rotations < 0)
			handle_reverse_rotation_b(head_b, head_a, 'a');
		else
			handle_opposite_direction_b(head_b, head_a, 'a');
		push(head_a, head_b, 'a');
	}
}

// This function is used to sort
// stacks with more than 3 nodes.
void	sort_bigger_stack(t_list **head_a, t_list **head_b)
{
	t_list	*min;
	int		origin_rotations;

	push(head_b, head_a, 'b');
	push(head_b, head_a, 'b');
	sort_in_descendig_to_b(head_a, head_b);
	handle_up_to_3(head_a);
	sort_in_ascendig_to_a(head_a, head_b);
	min = ft_lst_find_min(*head_a);
	origin_rotations = rotations_to_top(*head_a, min);
	if (origin_rotations < 0)
		while (origin_rotations++)
			reverse_rotate(head_a, 'a');
	else
		while (origin_rotations--)
			rotate(head_a, 'a');
}
