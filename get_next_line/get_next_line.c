/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/12/01 14:59:50 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_read(int fd, char *buffer)
{
	int	readed_bytes;
	/*char	*str;
	
	str = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str)
	{
		free(str);
		return (0);	
	}*/
	readed_bytes = read(fd, buffer, BUFFER_SIZE);
	//ft_strlcpy(str, buffer);
	//free(str);
       	printf("readed_bytes equal to %d \n", readed_bytes);	
	//printf("buffer value after read is -> %s \n", buffer);
	// when read returns 0, it means it reaches the end of file,
	// keep it in mind, i should fix that late
	
	return (readed_bytes);
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

char	*ft_backup(char *buffer,int readed_bytes)
{
	char	*backup;
	int	buffer_size;

	buffer_size = ft_strlen(buffer);
	backup = calloc((buffer_size + readed_bytes + 1), sizeof(char));
	if (!backup)
	{
		free(backup);
		return (NULL);
	}

	ft_strlcpy(buffer, backup);
	//free(buffer);
	return (backup);

}

char	*ft_update_buffer(char *buffer, int line_size, size_t readed_bytes)
{
	int	buffer_size;
	char	*new_buffer;
	int	i;

	i = 0;
	buffer_size = ft_strlen(buffer);
	new_buffer = calloc((buffer_size + readed_bytes + 1), sizeof(char));
	while (i < (buffer_size - line_size))
	{
		//printf("buffer value on loop -> %s \n", new_buffer);
		new_buffer[i] = buffer[buffer_size - (buffer_size - line_size) + i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer = NULL;
	char		*line;
	int		line_length;
	int		readed_bytes;
	static char		*backup;

	line_length = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	readed_bytes = ft_read(fd, buffer);
	if (readed_bytes <= 0)
		return (NULL);
	//saves a backup of the current buffer
	//printf("backup first value-> %s \n",backup);
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
			//printf("line value is -> %s \n", line);
			backup = ft_update_buffer(backup, line_length, readed_bytes);
			//printf("backup after update value is -> %s \n",backup);
		}else{
			//backup = ft_backup(buffer, readed_bytes);
			readed_bytes = ft_read(fd, buffer);
			backup = ft_strjoin(backup,buffer);
			//readed_bytes = ft_read(fd, buffer);
			//printf("backup equals to -> %s \n", backup);	
		}
	}
	free(buffer);
	//printf("buffer final value is -> %s \n", buffer);
	return (line);
}

