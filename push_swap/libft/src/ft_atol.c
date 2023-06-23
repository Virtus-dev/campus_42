/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:27 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/16 16:27:59 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
* Transform a string into a long data type
* in order to handle errors in the push_swap function.
* (returns an int, checking first if is less than the INT_MAX and casting it into an int).
*/ 
 
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		//printf("str = %c\n", str[i]);
		result = result * 10 + (str[i] - '0');
		//printf("result = %ld\n", result);
		i++;
	}
	return (result * sign);
}