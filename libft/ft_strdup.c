/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:18:06 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/04 13:26:03 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (0);
	ft_memcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
