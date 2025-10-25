/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:38:59 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/14 16:03:03 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static int				bits_counter;
	static unsigned char	c;
	static char				*message;
	static int				chars_counter;

	if (signal == SIGUSR1)
		c |= (1 << bits_counter);
	if (!chars_counter && !c && !bits_counter)
		message = NULL;
	bits_counter++;
	if (bits_counter > 7)
	{
		bits_counter = 0;
		if (!handle_string(message, c, &chars_counter))
		{
			message = NULL;
			return ;
		}
		message = get_string(message, c, chars_counter);
		c = 0;
	}
}
