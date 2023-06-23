/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_aux_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:26:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/23 11:55:49 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_matrix_size(char** matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_free_matrix(char** matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

// Checks if is, or is not a number
int	ft_is_nbr(char* s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

// Checks if there's duplicates on a int*

int		ft_isdup(char** argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[i] == argv[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
