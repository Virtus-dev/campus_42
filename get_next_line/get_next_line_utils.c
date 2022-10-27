/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:00 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/27 18:31:44 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>
 #include <fcntl.h>
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, '\0', size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;

	string = (unsigned char *) b;
	while (len > 0)
	{
		*(string++) = (unsigned char) c;
		len--;
	}
	return (b);
}	

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*combinedstring;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (0);
		combinedstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!combinedstring)
		return (0);

	while (s1 != NULL && s1[i] != '\0')
	{
		combinedstring[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		combinedstring[i] = s2[j];
		i++;
		j++;
	}
	combinedstring[i] = '\0';
	return (combinedstring);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && (char)c != *str)
		str++;
	if ((char)c == *str)
		return ((char *)str);
	return (0);
}
