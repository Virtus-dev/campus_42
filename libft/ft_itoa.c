/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:44:10 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/04 13:45:35 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Entero minimo - 2 147 483 648

char	*ft_itoa(int n)
{
	int	maxInt;

	minInt = 2147483648;
	while (n < maxInt)
	{
		if (n < 9)
			return (n + '0');
		else
		{
			
