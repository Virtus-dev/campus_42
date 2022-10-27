/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/27 14:48:15 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		readed_bytes;
	char		*str;
	
	readed_bytes = read(fd, str, BUFFER_SIZE);
	while (readed_bytes > 0)
	{
		buffer = strjoin(buffer, str);
		if (ft_strchr(str, '\n'))
				break;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int	i;
	char	*line;
	
	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

void	ft_update_buffer(char *buffer, int line_size)
{
	int	buffer_size;
	char	*new_buffer;

	buffer_size = ft_strlen(buffer);
	new_buffer = malloc((buffer_size - line_size) * sizeof(char));
	while (i < (buffer_size - line_size))
		new_buffer[i] = buffer[line_size + i];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ft_read(fd, buffer);
