/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:35:27 by arigonza          #+#    #+#             */
/*   Updated: 2023/01/27 13:49:52 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *string, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunsignednbr(unsigned int nbr, int *count);
void	ft_printhexa(unsigned long nbr, char h, int *count);
void	ft_printptr(void *ptr, int *count);

#endif
