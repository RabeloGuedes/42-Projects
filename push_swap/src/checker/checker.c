/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:48:10 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/07 15:23:55 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	apply_swap(char *str, t_list **head_a, t_list **head_b, char swap_type)
{
	if (str[1] == 'a')
		swap(head_a, swap_type);
	else if (str[1] == 'b')
		swap(head_b, swap_type);
	else if (str[1] == 's')
		ss(head_a, head_b, swap_type);
}

void	apply_push(char *str, t_list **head_a, t_list **head_b, char push_type)
{
	if (str[1] == 'a')
		push(head_a, head_b, push_type);
	else if (str[1] == 'b')
		push(head_b, head_a, push_type);
}

void	apply_rotate(char *str, t_list **head_a,
	t_list **head_b, char rotate_type)
{
	if (ft_strlen(str) == 3 && str[0] == 'r')
	{
		if (str[1] == 'a')
			rotate(head_a, rotate_type);
		else if (str[1] == 'b')
			rotate(head_b, rotate_type);
		else if (str[1] == 'r')
			rr(head_a, head_b, rotate_type);
	}
	else if (ft_strlen(str) == 4 && str[0] == 'r' && str[1] == 'r')
	{
		if (str[2] == 'a')
			reverse_rotate(head_a, rotate_type);
		else if (str[2] == 'b')
			reverse_rotate(head_b, rotate_type);
		else if (str[2] == 'r')
			rrr(head_a, head_b, rotate_type);
	}
}

void	movement_applier(char *str, t_list **head_a, t_list **head_b)
{
	if (ft_strlen(str) == 3 && str[0] == 's')
		apply_swap(str, head_a, head_b, 'n');
	else if (ft_strlen(str) == 3 && str[0] == 'p')
		apply_push(str, head_a, head_b, 'n');
	else 
		apply_rotate(str, head_a, head_b, 'n');
}

int	main(int ac, char **av)
{
	t_list	**head_a;
	t_list	**head_b;

	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		head_a = (t_list **)malloc(sizeof(t_list *));
		head_b = (t_list **)malloc(sizeof(t_list *));
		if (!head_a || !head_b)
			return (0);
		*head_a = create_nodes(av);
		*head_b = NULL;
		if (!*head_a)
			return (0);
		read_commands_check_order(head_a, head_b);
		free_nodes(*head_a);
		free_nodes(*head_b);
		free(head_a);
		free(head_b);
	}
	return (0);
}
