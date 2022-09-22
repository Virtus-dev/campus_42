/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:05:28 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/22 12:10:11 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memmove(void *str1, const void *str2, size_t n)
{
	if (!str1 && !str2)
		return (0);
	if (str1 > str2)
	{
		while (n > 0)
		{
			*(char*)(str1 + n) = *(char*)(str2 + n);
			n--;
		}
	}
	else
		{
			i = 0;
			while (i < (int)n)
			{
				*(char*)(str1 + n) = *(char*)(str2 + n);
				n++;
			}
		}
	return (str1);
	}

