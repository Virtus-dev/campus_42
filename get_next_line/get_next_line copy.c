/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/12/12 17:58:01 by arigonza         ###   ########.fr       */
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = calloc((i + 2) , sizeof(char));
	if(!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_backup(char *buffer,int readed_bytes)
{
	char	*backup;
	int		buffer_size;

	buffer_size = ft_strlen(buffer);
	backup = calloc((buffer_size + readed_bytes + 2), sizeof(char));
	if (!backup)
	{
		//free(backup);
		return (NULL);
	}

	ft_strlcpy(buffer, backup);
	//free(buffer);
	return (backup);

}

char	*ft_update_buffer(char *buffer, int line_size)
{
	int		buffer_size;
	char	*new_buffer;
	int		i;

	i = 0;
	buffer_size = ft_strlen(buffer);
	new_buffer = calloc((buffer_size - line_size + 2), sizeof(char));
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
	static char		*backup = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_length = 0;
	buffer = calloc((BUFFER_SIZE + 1) , sizeof(char));
	readed_bytes = read(fd, buffer, BUFFER_SIZE);
	if (readed_bytes < 0)
	{
		free(backup);
		free(buffer);
		backup = NULL;
		return (NULL);
	}
	if (backup == NULL)
		backup = ft_backup(buffer, readed_bytes);
	else
		backup = ft_strjoin(backup, buffer);
	while (line_length <= 0 && readed_bytes != 0)
	{
		if (ft_strchr(buffer,'\n'))
		{
			line = ft_get_line(backup);
			line_length = ft_strlen(line);
			backup = ft_update_buffer(backup, line_length);
		}else{
			readed_bytes = read(fd,buffer,BUFFER_SIZE);
			backup = ft_strjoin(backup,buffer);
		}
	}
	free(buffer);
	return (line);
}

