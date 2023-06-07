/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_aux_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:26:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/07 22:25:40 by arigonza         ###   ########.fr       */
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
	while (matrix)
		free(matrix[i]);
	free(matrix);
}

// checks if there's o there's not a space or tabs
int	is_space(char c)
{
	int	i;
	
	i = 0;
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);		
}

// Checks if there's duplicates on a int*
int		ft_isdup(int* nb)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = sizeof(nb) / sizeof(nb[0]);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nb[i] == nb[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}