/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:00 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/14 12:29:58 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (i < (count * size))
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*combinedstring;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	j = 0;
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	combinedstring = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!combinedstring)
		return (NULL);
	while (i < len_s1)
	{
		combinedstring[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		combinedstring[i++] = s2[j++];
	combinedstring[i] = '\0';
	free(s1);
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
