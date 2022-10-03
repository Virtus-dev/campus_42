/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:18:06 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/29 16:35:33 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int	i;

	i = 0;
	if (!(cpy = (char*)malloc(ft_strlen(s1) + 1)))
		return (0);
	ft_memcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
