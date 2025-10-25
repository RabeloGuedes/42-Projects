/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:54:31 by arabelo-          #+#    #+#             */
/*   Updated: 2023/07/25 12:40:52 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_special_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!join)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
	}
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	free(s1);
	return (join);
}
