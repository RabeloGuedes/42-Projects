/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:40:09 by arabelo-          #+#    #+#             */
/*   Updated: 2023/05/14 14:25:27 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_whole_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_one_line(buffer);
	buffer = new_buffer_storage(buffer);
	return (line);
}

char	*get_whole_file(int fd, char *buffer)
{
	char	*str;
	int		r_status;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	r_status = 1;
	while (!ft_strchr(buffer, '\n') && r_status)
	{
		r_status = read(fd, str, BUFFER_SIZE);
		if (r_status == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		str[r_status] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_one_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlen(buffer))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = buffer[i];
	return (line);
}

char	*new_buffer_storage(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}
