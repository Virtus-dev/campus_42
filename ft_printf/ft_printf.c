/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:11:36 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/25 17:55:56 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format == 'd'|| format == 'i')
		ft_putnbr(va_arg(args,int), count);
	if (format == 'u')
		ft_putunsignednbr(va_arg(args, unsigned int), count);
	if (format == 'x' || format == 'X')
		ft_printhexa(va_arg(args, int), format, count);
	if (format == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *string, ...)
{	
	va_list	args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			
			ft_format(args, string[++i], &count);
			i += 2;
		}
		else
			ft_putchar(string[i++], &count);
	}
	va_end(args);
	return (count);
}
