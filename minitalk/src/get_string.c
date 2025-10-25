/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:30 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:50 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_string(char *old_message, unsigned char c, int chars_counter)
{
	char	*new_message;

	new_message = (char *)malloc(sizeof(char) * (chars_counter + 1));
	if (!new_message)
	{
		if (old_message)
			free(old_message);
		exit(EXIT_FAILURE);
	}
	if (old_message)
	{
		ft_strlcpy(new_message, old_message, (chars_counter + 1));
		free(old_message);
	}
	new_message[chars_counter - 1] = c;
	new_message[chars_counter] = '\0';
	return (new_message);
}
