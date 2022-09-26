/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:03:02 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/26 12:03:02 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strchr(const char *str, int c)
{
    char            *aux;
    unsigned int    index;

    index = 0;
    while (!str)
    {
        if (str[index] == c)
        {
            while (!str[index])
            {
                aux = str[index];
                index++;
                *aux++;
            }
            return (aux);
        }
        return (0);
    }
}