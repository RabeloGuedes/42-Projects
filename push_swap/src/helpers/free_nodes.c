/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:26:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 10:37:06 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function iterate over the stack
// from a certain node, assuming it is
// the head, and frees the content of
// each node as well as the node itself.
void	free_nodes(t_list *head)
{
	t_list	*curr;

	curr = head;
	while (curr)
	{
		curr = curr->next;
		free(head->content);
		free(head);
		head = curr;
	}
}
