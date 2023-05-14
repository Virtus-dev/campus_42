/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_aux_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:26:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/04/27 19:26:09 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

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