/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:34:03 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:23 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal_bonus(int signal, siginfo_t *siginfo, void *addr)
{
	static int				bits_counter;
	static unsigned char	c;
	static char				*message;
	static int				chars_counter;

	(void)addr;
	if (signal == SIGUSR1)
		c |= (1 << bits_counter);
	if (!chars_counter && !c && !bits_counter)
		message = NULL;
	bits_counter++;
	if (bits_counter > 7)
	{
		bits_counter = 0;
		if (c == 0 && message)
		{
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				ft_putendl_fd("Could not notify the client!", 2);
		}
		if (!handle_string(message, c, &chars_counter))
			return ;
		message = get_string(message, c, chars_counter);
		c = 0;
	}
}
