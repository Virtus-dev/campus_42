/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/29 14:30:18 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /*The atoi() function converts the initial portion of the string pointed to by str to int representation.
 It is equivalent to:
(int)strtol(str, (char **)NULL, 10);
While the atoi() function uses the current locale, the atoi_l() function may be passed a locale directly. See xlocale(3) for more information.*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signo;

	i = 0;
	result = 0;
	signo = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * signo);
}
