/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:26:03 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 11:27:53 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function displays a
// stack before and after swap.
void	display_swap(t_list	**head)
{
	ft_printf("Before Swap A:\n");
	display_nodes(*head);
	swap(head, 'a');
	ft_printf("After Swap A:\n");
	display_nodes(*head);
}

// This function displays two stacks
// before and after push.
void	display_push(t_list **head_a, t_list **head_b)
{
	ft_printf("Before Push A:\n");
	display_nodes(*head_a);
	ft_printf("Before Push B:\n");
	display_nodes(*head_b);
	push(head_a, head_b, 'a');
	ft_printf("After Push A:\n");
	display_nodes(*head_a);
	ft_printf("After Push B:\n");
	display_nodes(*head_b);
}

// This function displays a
// stack before and after rotate.
void	display_rotate(t_list **head, char rotate_type)
{
	ft_printf("Before rotate A:\n");
	display_nodes(*head);
	rotate(head, rotate_type);
	ft_printf("After rotate A:\n");
	display_nodes(*head);
}

// This function displays a stack
// before and after reverse rotate.
void	display_reverse_rotate(t_list **head, char rotate_type)
{
	ft_printf("Before rotate A:\n");
	display_nodes(*head);
	reverse_rotate(head, rotate_type);
	ft_printf("After rotate A:\n");
	display_nodes(*head);
}
