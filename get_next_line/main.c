/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:02:51 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/28 14:57:28 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*str;

	if (ac > 1)
	{
		int	fd = open(av[1], O_RDONLY);
		if (fd == - 1)
		{
			printf("open() failed\n");
			return (-1);
		}
		str = get_next_line(fd);
		printf("line: %s", str);
		free(str);
		if (close(fd) == -1)
		{
			printf("close() failed\n");
			return (-1);
		}
	}
	else
		printf("Usage ./a.out fileName\n");
	return (0);
}