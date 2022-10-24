/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/24 19:32:28 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	size_t	readed_bytes;
	static char	*buffer;
	
	buff = malloc((BUFFERED_SIZE + 1) * sizeof(char));
	//in case the malloc dont went well, return null and make free
	ft_free_null(*buffer);
	readed_bytes = read(fd, buffer, BUFFERED_SIZE);

	//checking if read() actually works
	//and going through the buffer moving it to the end of the line
	if (read_bytes != 0)
	{
		while (buffer != '\n')
			buferr++;
	}
	return (buffer); //returned buffer on the end of the line

}

static void	ft_free_null(char *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

char	*get_next_line(int fd)
{

}
	
