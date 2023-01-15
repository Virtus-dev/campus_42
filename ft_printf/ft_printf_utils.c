/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:30:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/15 18:54:37 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char *c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putnbr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar("-");
			n = n * -1;
		}

		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10 + '0');
		}
	}
}
