
#include "push_swap.h"

/*
* Transform a string into a long data type
* in order to handle errors in the push_swap function.
* (returns an int, checking first if is less than the INT_MAX and casting it into an int).
*/ 
 
long	ft_long_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}