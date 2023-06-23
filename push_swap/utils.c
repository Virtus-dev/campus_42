

#include "push_swap.h"

int ft_is_sorted(int* values, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (values[i] > values[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void    ft_print_stack(t_stack* stack, char c)
{
    Node* current;

    current = stack->head;
    while (current)
    {
        if (c == 'a' || c =='A')
            ft_printf("stack A: %d\n", current->value);
        else if (c == 'b' || c == 'B')
            ft_printf("stack B: %d\n", current->value);
        current = current->next;
    }
}

// Initialize an empty stack
void ft_initialize_stack(t_stack* stack)
{
    stack->head = NULL;
    stack->size = 0;
}

// Function to get the maximum value in the stack
int get_max_value(t_stack* stack)
{
    int max_value = INT_MIN;
    Node* current = stack->head;

    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
        }
        current = current->next;
    }

    return max_value;
}