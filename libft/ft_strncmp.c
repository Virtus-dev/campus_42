/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:48:54 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/27 19:40:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n)
	{
		s1++;
		s2++;
		i++;
	}
		if (*s1 < *s2)
			return (-1);
		if (*s1 == *s2)
			return (0);
		if (*s1 > *s2)
			return (1);
}
