/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:00 by arigonza          #+#    #+#             */
/*   Updated: 2022/11/29 12:06:06 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>
 #include <fcntl.h>
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t 	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (i < size)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*combinedstring;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	combinedstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!combinedstring)
		return (0);
	while (s1 != NULL && s1[i] != '\0')
	{
		combinedstring[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
		combinedstring[i++] = s2[j++];
	combinedstring[i] = '\0';
	return (combinedstring);
}

void	ft_strlcpy(char const *src, char *dst)
{
	int	i;
	
	i = 0;	
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
		str++;
	if ((char)c == *str)
		return ((char *)str);
	return (0);
}

