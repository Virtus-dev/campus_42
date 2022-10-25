/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/25 13:44:55 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		readed_bytes;
	static char	*buffer;
	char		tmp[ARG_MAX];
	int		i;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//in case the malloc dont went well, return null and make free
	ft_free_null(buffer);
	readed_bytes = read(fd, buffer, BUFFER_SIZE);

	i = 0;
	//checking if read() actually works
	//and going through the buffer moving it to the end of the line
	if (readed_bytes != 0)
	{
		while (*buffer != END_OF_LINE)
			tmp[i++] = buffer++;
	}else
		return NULL;
	return (ft_strdup(tmp)); //returned a copy with the line readed

}

static void	ft_free_null(char *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}
	
