/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:33:08 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 11:03:37 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function checks if the stack has more
// the one node.
int	size_checker(t_list **head)
{
	int	size;

	if (!head || !*head)
		return (0);
	size = ft_lstsize(*head);
	if (size > 1)
		return (1);
	return (0);
}
