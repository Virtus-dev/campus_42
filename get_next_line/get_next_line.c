/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/11/06 13:31:00 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_check_null(char buffer)
{
	if (buffer == NULL)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	else
	{

		aux = malloc((ft_strlen(buffer) + 1) * sizeof(char));
		if (!aux)
		{
			free(aux);
			return (NULL);
		}
		ft_strlcpy(buffer, aux);
		free(buffer);
		buffer = malloc(ft_strlen(aux + (BUFFER_SIZE + 1)) *sizeof(char));
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		ft_strlcpy(aux, buffer);
		free(aux);
	}
}
char	*ft_read(int fd, char *buffer)
{
	int	readed_bytes;
	char	*str = NULL;
	char	*aux;

	ft_check_null(buffer);
	str = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	readed_bytes = read(fd, str, BUFFER_SIZE);
	printf("readed_bytes equal to %d \n", readed_bytes);
	// when read returns 0, it means it reaches the end of file,
	// keep it in mind, i should fix that later
	if (readed_bytes <= 0)
		return (NULL);
	if (readed_bytes <= BUFFER_SIZE)
	{
		buffer = ft_strjoin(buffer, str);
		printf("After strjoin buffer value is -> %s \n", buffer);
	}
	free(str);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int	i;
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
	if (buffer[i] == '\n')
		line[i] = '\n';
	else if (buffer[i] == '\0')
		line[i] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer, int line_size)
{
	int	buffer_size;
	char	*new_buffer;
	int	i;

	i = 0;
	buffer_size = ft_strlen(buffer);
	new_buffer = malloc((buffer_size - line_size) * sizeof(char));
	while (i < (buffer_size - line_size))
	{
		new_buffer[i] = buffer[line_size + i];
		i++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int		line_length;

	buffer = ft_read(fd, buffer);
	line = ft_get_line(buffer);
	line_length = ft_strlen(line);
	while (line[line_length] != '\n')
	{
		buffer = ft_read(fd, buffer);
		line = ft_get_line(buffer);
		printf("line value is -> %s \n", line);
		buffer = ft_update_buffer(buffer, line_length);
		line_length = ft_strlen(line);
		printf("Buffer value after the update -> %s \n", buffer);
	}
	//buffer = ft_update_buffer(buffer, line_length);
	//printf("Buffer value after the update -> %s \n", buffer);
	return (line);
}

int main()
{
	int fd;
	fd = open("./1char.txt", O_RDONLY);
	printf("get_next_line output -> %s", get_next_line(fd));
}
