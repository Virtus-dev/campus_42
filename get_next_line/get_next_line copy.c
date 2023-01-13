/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/13 17:42:36 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_calloc((i + 2) , sizeof(char));
	if(!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i] = '\n';
	return (line);
}

char	*ft_update_buffer(char *buffer, int line_size)
{
	int		buffer_size;
	char	*new_buffer;
	int		i;

	i = 0;
	buffer_size = ft_strlen(buffer);
	new_buffer = ft_calloc((buffer_size - line_size + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < (buffer_size - line_size))
	{
		new_buffer[i] = buffer[buffer_size - (buffer_size - line_size) + i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	int				line_length;
	int				readed_bytes;
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_length = 0;
	buffer = ft_calloc((BUFFER_SIZE + 1) , sizeof(char));

	if (!backup)
		backup = ft_calloc(1,1);
	readed_bytes = read(fd, buffer, BUFFER_SIZE);
	if (readed_bytes <  0 && *backup == '\0')
	{
		free(buffer);
		free(backup);
		return (NULL);
	}
		backup = ft_strjoin(backup, buffer);
	while (!ft_strchr(backup,'\n') && readed_bytes != 0)
	{
			readed_bytes = read(fd,buffer,BUFFER_SIZE);
			backup = ft_strjoin(backup,buffer);
	}
	line = ft_get_line(backup);
	line_length = ft_strlen(line);
	backup = ft_update_buffer(backup, line_length);

	free(buffer);
	return (line);
}

