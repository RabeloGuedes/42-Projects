/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:26:37 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/14 13:19:07 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t server_pid, unsigned char c)
{
	unsigned int	i;

	i = 1;
	while (i <= 128)
	{
		if ((c & i) == 0)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("Error: Message not completely received!", 2);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("Error: Message not completely received!", 2);
				exit(EXIT_FAILURE);
			}
		}
		i *= 2;
		usleep(WAIT_TIME);
	}
}
