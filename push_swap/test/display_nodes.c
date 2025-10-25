/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:10 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 11:32:12 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function displays a
// single node informations,
// content, it's address
// (pointer address) and the
// address of the next one,
// if it exists (pointer address).
void	display_node_infos(t_list *node)
{
	ft_printf("	{\n		data: %i,\n", *(int *)(node->content));
	ft_printf("		next: %p,\n", node->next);
	ft_printf("		address: %p\n", node);
	ft_printf("	},\n");
}

// This function displays all
// nodes on a stack with it's
// content, it's address
// (pointer address) and the
// address of the next one,
// if it exists (pointer address).
void	display_nodes(t_list *stack)
{
	ft_printf("[\n");
	while (stack)
	{
		display_node_infos(stack);
		stack = stack->next;
	}
	ft_printf("]\n");
}

// This function displays all nodes
// on a stack with it's content. 
void	display_nodes_simple(t_list *stack)
{
	while (stack)
	{
		if (stack->next)
			ft_printf("%i -> ", *(int *)stack->content);
		else
			ft_printf("%i\n", *(int *)stack->content);
		stack = stack->next;
	}
}
