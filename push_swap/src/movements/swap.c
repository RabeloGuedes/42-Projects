/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:51:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/24 16:17:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function swaps the first and the
// second nodes from a given stack, if 
// there is at least two nodes.
void	swap(t_list **head, char swap_type)
{
	t_list	*first;
	t_list	*second;

	if (*head && (*head)->next)
	{
		first = *head;
		second = (*head)->next;
		first->next = second->next;
		second->next = first;
		*head = second;
	}
	if (swap_type == 'a')
		ft_printf("sa\n");
	else if (swap_type == 'b')
		ft_printf("sb\n");
}

// This function swaps the first and the
// second nodes from a two given stacks.
void	ss(t_list **head_a, t_list **head_b, char swap_type)
{
	swap(head_a, swap_type);
	swap(head_b, swap_type);
	if (swap_type == 's')
		ft_printf("ss\n");
}
