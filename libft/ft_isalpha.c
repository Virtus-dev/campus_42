/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:09:38 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/22 12:57:50 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{	
	if ((c <= 'a' & c >= 'z') || (c <= 'A' & c >= 'Z'))
		return (1);
	else
		return (0);

}
