/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:31:12 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 11:01:21 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function checks if two given integers
// passed by parameter are in asceding order.
int	is_ascending(int a, int b)
{
	return (a <= b);
}

// This function checks if two given integers
// passed by parameter are in desceding order.
int	is_descending(int a, int b)
{
	return (b <= a);
}

// This function checks if the given stack is ordered
// based on the given function, both the stack and the
// function are passed as parameters, the function could
// be e.g. the is_ascending.
int	is_ordered(t_list *head, int (*cmp)(int, int))
{
	if (!head)
		return (0);
	while (head->next)
	{
		if (!(cmp(*(int *)head->content, *(int *)head->next->content)))
			return (0);
		head = head->next;
	}
	return (1);
}
