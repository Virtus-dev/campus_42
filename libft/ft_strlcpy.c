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
	unsigned int	i;
	unsigned int	index;

	i = 0;
	index = 0;
	while (src[i] != "\0")
	{
		i++;
		if (dstsize != 0)
		{
			while (src[index] != "\0" && index < (size -1))
			{
				dest[index] = src[index];
				index++;
			}
		}
		return (i + 1);
	}
}	
