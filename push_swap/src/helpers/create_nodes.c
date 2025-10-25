/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:26:28 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 10:34:30 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function creates a node and set
// the content of the node to hold the
// integer passed by the parameter and
// the next pointer to NULL, assuming
// it is the last one and returns it.
t_list	*create_node(int data)
{
	t_list	*new_node;
	int		*ptr_data;

	new_node = (t_list *)malloc(sizeof(t_list));
	ptr_data = (int *)malloc(sizeof(int));
	if (!new_node || !ptr_data)
		return (NULL);
	new_node->next = NULL;
	*ptr_data = data;
	new_node->content = ptr_data;
	return (new_node);
}

// This function uses the create_node function
// to create dynamically all the necessaries nodes
// based on the arguments and returns the head
// (first node) of the created stack.
t_list	*create_nodes(char **args)
{
	t_list	*curr;
	t_list	*ref;

	curr = create_node(ft_atoi(*args++));
	if (!curr)
		return (NULL);
	ref = curr;
	while (*args)
	{
		curr->next = create_node(ft_atoi(*args++));
		curr = curr->next;
	}
	return (ref);
}
