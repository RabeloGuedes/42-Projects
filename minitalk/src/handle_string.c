/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:22:38 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:50 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	handle_string(char *message, unsigned char c, int *chars_counter)
{
	if (!c)
	{
		*chars_counter = 0;
		if (message)
		{
			ft_printf("%s", message);
			free(message);
		}
		return (0);
	}
	(*chars_counter)++;
	return (1);
}
