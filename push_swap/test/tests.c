/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:07 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/18 11:33:28 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function tests if the push function works properly.
void	test_push(char **args)
{
	t_list	**head_a;
	t_list	**head_b;
	char	**args_b;

	head_a = (t_list **)malloc(sizeof(t_list *));
	head_b = (t_list **)malloc(sizeof(t_list *));
	args_b = (char **)malloc(sizeof(char *));
	*args_b = (char *)malloc(sizeof(char) + 1);
	args_b[0][0] = '6';
	args_b[0][1] = '\0';
	*head_a = create_nodes(args);
	*head_b = create_nodes(args_b);
	if (!*head_a || !*head_b)
		return ;
	display_push(head_a, head_b);
	free_nodes(*head_a);
	free_nodes(*head_b);
	free(head_a);
	free(head_b);
	free(*args_b);
	free(args_b);
}

// This function tests if the rotate function works properly.
void	test_rotate(char **args)
{
	t_list	**head_a;

	head_a = (t_list **)malloc(sizeof(t_list *));
	*head_a = create_nodes(args);
	if (!*head_a)
		return ;
	display_rotate(head_a, 'a');
	free_nodes(*head_a);
	free(head_a);
}

// This function tests if the reverse rotate function works properly.
void	test_reverse_rotate(char **args)
{
	t_list	**head_a;

	head_a = (t_list **)malloc(sizeof(t_list *));
	*head_a = create_nodes(args);
	if (!*head_a)
		return ;
	display_reverse_rotate(head_a, 'a');
	free_nodes(*head_a);
	free(head_a);
}

// This function tests if the swap function works properly.
void	test_swap(char **av)
{
	t_list	**head;

	head = (t_list **)malloc(sizeof(t_list *));
	*head = create_nodes(av);
	display_swap(head);
	free_nodes(*head);
	free(head);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!args_checker(++av))
			return (0);
		test_push(av);
	}
	return (0);
}
