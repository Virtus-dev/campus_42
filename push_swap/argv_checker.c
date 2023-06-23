/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:51:58 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/23 12:58:43 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_param_checker(int argc, char** argv)
{
    int	i;
	char**	splited;
	int*	parsed;
	(void) argc;

	i = 1;
	if (argc == 2)
	{
		splited = ft_split(argv[1], ' ');
		parsed = ft_parse(splited, 0);
	if (!parsed || !splited)
		return (ft_free_matrix(splited), free(parsed), 0);
	while (i < argc)
	{
		if (!ft_is_nbr(splited[i]))
			return (ft_free_matrix(splited), free(parsed), 0);
		i++;
	}
	if (ft_isdup(splited))
		return (ft_free_matrix(splited), free(parsed), 0);
	if(ft_is_sorted(parsed, ft_matrix_size(splited)))
		return (ft_free_matrix(splited), free(parsed), 0);
	return (1);
	}
	
	parsed = ft_parse(argv, 1);
	if (!parsed)
		return (free(parsed), 0);
	while (i < argc)
	{
		if (!ft_is_nbr(argv[i]))
			return (free(parsed), 0);
		i++;
	}
	if (ft_isdup(argv))
		return (free(parsed), 0);
	if(ft_is_sorted(parsed, ft_matrix_size(argv)))
		return (free(parsed), 0);
	return (1);
}

// argc should be 1 if there's more than 2 argc or 0 in case there's only 2
int*	ft_parse(char** splited, int argc)
{
	int		i;
	int		j;
	int		size;
	int*	values;

	i = argc;
	j = 0;
	size = ft_matrix_size(splited);
	values = (int*) malloc (ft_matrix_size(splited) * sizeof(int));
	if (!values)
		return (free(values), NULL);
	while (i < size)
	{
		if (ft_atol(splited[i]) > INT_MAX || ft_atol(splited[i]) < INT_MIN)
		{
			return (free(values), NULL);
		}
		else
			values[j] = (int)ft_atol(splited[i]);
		j++;
		i++;
	}
	return (values);
}