/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:30:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/27 19:56:14 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', count);
			n = n * -1;
		}

		if (n > 9)
			ft_putnbr(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1,"(null)",6);
		(*count) += 6;
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++], count);
	}
}

void	ft_putunsignednbr(unsigned int nbr, int *count)
{
	if (nbr > 9)	
		ft_putunsignednbr(nbr / 10, count);
	ft_putchar((nbr % 10) + '0', count);
}

void	ft_printhexa(unsigned long nbr, char h,int *count)
{
	int	i;
	char	*base;
	char	str[25];

	i = 0;
	if (h == 'x')
		base = "0123456789abcdef";
	if (h == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
		return (ft_putchar('0', count));
	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], count);
}

void	ft_printptr(void *ptr, int *count)
{
	if (ptr == NULL)
		ft_putstr("(nil)", count);
	else
	{	
	ft_putstr("0x", count);
	ft_printhexa((unsigned long)ptr, 'x', count);
	}
}
