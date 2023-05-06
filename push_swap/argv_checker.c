

#include "push_swap.h"

int    *ft_param_checker(int argc, char* argv[])
{
    size_t	i;
	size_t	j;
	char**	splited;
	int*	values;

	values = (int*) malloc ((argc - 1) * sizeof(int));
	i = 0;
	j = 0;
	if (argc > 1)
	{
		while (i < (argc - 1))
		{
			splited[i] = ft_split(argv[i + 1], ' ');
			while (splited[i])
			{
				if (ft_isdup(splited) == 1)
				{
					free(values);
					free(splited);
					return (0);
				}
				if (ft_isdigit(splited[i][j]) == 0)
				{
					free(values);
					free(splited);
					return (0);
				}
				values[j++] = ft_atoi(splited[i++]);
			}
		}
		return (1);
	}
	return (0);
}

int		ft_isdup(char** matrix)
{
	int	i;
	int	j;
	char** set;
	char* value;

	set = (char**) malloc (sizeof(char*));
	i = 0;
	j = 0;
	if (!set)
		return 0;
	while (matrix[i])
	set[i++] = NULL;
	i = 0;
	while (matrix[i])
	{
		value = matrix[i];
		while (matrix[i][j])
		{
			if (set != NULL && (ft_strcmp(set[i][j], value[j]) == 0))
			{
				free(set);
				free(value);
				return 1;
			}
			j++;
		}
		j = 0;
		set[i++] = value;
	}
	free(set);
	return 0;
}