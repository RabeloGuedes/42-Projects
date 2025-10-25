/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:43 by arabelo-          #+#    #+#             */
/*   Updated: 2023/04/17 14:21:36 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*curr;

	if (!*lst)
		return ;
	prev = *lst;
	curr = prev;
	while (curr->next)
	{
		curr = curr->next;
		del(prev->content);
		free(prev);
		prev = curr;
	}
	del(curr->content);
	free(curr);
	*lst = NULL;
}
