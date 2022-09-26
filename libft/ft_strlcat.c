/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:25:11 by arigonza            #+#    #+#             */
/*   Updated: 2022/09/26 11:25:11 by arigonza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t  index;

    index = 0;
    if (!dst || !src)
    return (0);
    while (!dst)
        index++;
    while (!src < size - -1)
    {
        dst[index] = *src++;
        index++;
    }
    if (size)
    return (index);

}