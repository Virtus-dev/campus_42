/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/27 18:31:11 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


 
char	*ft_read(int fd, char *buffer)
{
	int		readed_bytes;
	char	*str = NULL;

	str = calloc((BUFFER_SIZE + 1), sizeof(char));
	readed_bytes = read(fd, str, BUFFER_SIZE);
	

	while (readed_bytes > 0)
	{

		buffer = ft_strjoin(buffer, str);
		if (ft_strchr(str, '\n') || readed_bytes < BUFFER_SIZE)
			break ;
	}

	free(str);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;


	line = malloc((i + 1) * sizeof(char));
	i = 0;
	

	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*ft_update_buffer(char *buffer, int line_size)
{
	int		buffer_size;
	char	*new_buffer;
	int		i;

	i = 0;
	buffer_size = ft_strlen(buffer);
	new_buffer = malloc((buffer_size - line_size) * sizeof(char));
	while (i < (buffer_size - line_size))
		new_buffer[i] = buffer[line_size + 1];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	buffer = ft_read(fd, buffer);


	line = ft_get_line(buffer);


	ft_update_buffer(buffer, ft_strlen(line));
	

	return (line);
}
