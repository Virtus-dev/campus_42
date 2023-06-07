/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:51:58 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/07 23:01:35 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *ft_param_checker(int argc, char* argv[])
{
    size_t	i;
	size_t	j;
	char**	splited;

	i = 0;
	splited = ft_split(argv[1], ' ');
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (ft_isdigit(splited[i][j]) == 0)
			{
				ft_free_matrix(splited);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (ft_isdup(ft_parse(splited)))
		return (ft_free_matrix(splited), 0);
	return (1);
}

int	ft_parse(char** splited)
{
	int		i;
	int		j;
	int*	values;

	i = 0;
	j = 0;
	while (splited[i])
	{
		if (ft_long_atoi(splited[i]) > INT_MAX || ft_long_atoi(splited[i]) < INT_MIN)
		{
			//error message
			ft_free_matrix(splited);
			return (NULL);
		}
		else
			values[j++] = (int)ft_long_atoi(splited[i]);
		i++;
	}
	return (values);
}