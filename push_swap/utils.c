
#include "push_swap.h"

int ft_is_sorted(int* values)
{
    int i;
    int size;

    i = 0;
    size = sizeof(values) / sizeof(values[0]);
    while (i < size)
    {
        if (values[i] > values[i + 1])
            return (0);
    }
    return (1);
}