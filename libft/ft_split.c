/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:28 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/03 16:51:45 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counterwords(const char *s, char c)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char**	splitedstr;

	i = 0;
	j = 0;
	splitedstr = malloc(sizeof(char*) * ft_counterwords(s, c));
	if (!splitedstr)
		return (0);
	while (s[i] != '\0' && ft_counterwords(s, c) > 0)
	{
		if (s[i] == c && s[i + 1] != c)
		{
			**splitedstr = ft_substr(s, j, (i - j));
			j = i;
			splitedstr++;
		}
		i++;
	}
	return (splitedstr);
}
