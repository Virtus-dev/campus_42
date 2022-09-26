/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:05:43 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/22 11:21:16 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		i++;
		while (src[index] && index < (dstsize -1))
		{
			dst[index] = src[index];
			index++;
		}
	}
	if (dstsize)
		return (i);
}	
