/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:39:40 by arigonza          #+#    #+#             */
/*   Updated: 2023/04/19 22:39:49 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack* stackA, t_stack* stackB)
{
    while (stackA->head != NULL)
    {
        int max_value = stackA->head->value;
        int max_position = 0;
        node* current = stackA->head;
        int position = 0;

        // Encuentra el valor máximo y su posición en stackA
        while (current != NULL)
        {
            if (current->value > max_value)
            {
                max_value = current->value;
                max_position = position;
            }
            current = current->next;
            position++;
        }

        if (max_position == 0)
        {
            ft_pb(stackB, stackA); // Empuja el valor máximo a stackB
        }
        else if (max_position <= stackA->size / 2)
        {
            while (max_position > 0)
            {
                ft_ra(stackA); // Rota stackA en dirección ra para mover el valor máximo a la cima
                max_position--;
            }
            ft_push_b(stackA, stackB); // Empuja el valor máximo a stackB
        }
        else
        {
            max_position = stackA->size - max_position;
            while (max_position > 0)
            {
                ft_rra(stackA); // Rota stackA en dirección rra para mover el valor máximo a la cima
                max_position--;
            }
            ft_pb(stackB, stackA); // Empuja el valor máximo a stackB
        }
    }
    while (stackB->head != NULL)
    {
        ft_pa(stackA, stackB); // Mueve los elementos de stackB a stackA en orden descendente
    }       
}


void	ft_sa(t_stack* stackA)
{
	if (!stackA || !stackA->head)
		return;
	node* first = pop(stackA);
	node* second = pop(stackA);
	insert_node_head(stackA, first);
	insert_node_head(stackA, second);
}

void	ft_pa(t_stack* stackA, t_stack* stackB)
{
	insert_node_head(stackA, pop(stackB));
}

void	ft_sb(t_stack* stackB)
{
	if (!stackB || !stackB->head)
		return;
	node* first = pop(stackB);
	node* second = pop(stackB);
	insert_node_head(stackB, first);
	insert_node_head(stackB, second);
}

void	ft_pb(t_stack* stackB, t_stack* stackA)
{
	insert_node_head(stackB, pop(stackA));
}

void	ft_ss(t_stack* stackA, t_stack* stackB)
{
	ft_sa(stackA);
	ft_sb(stackB);
}

void	ft_ra(t_stack* stackA)
{
	insert_node_tail(stackA, pop(stackA));
}

void	ft_rb(t_stack* stackB)
{
	insert_node_tail(stackB, pop(stackB));
}

void	ft_rr(t_stack* stackA, t_stack* stackB)
{
	insert_node_tail(stackA, pop(stackA));
	insert_node_tail(stackB, pop(stackB));
}

void	ft_rra(t_stack* stackA)
{
	if (!stackA || !stackA->head || !stackA->head->next)
		return;
	node* prev = NULL;
	node* current = stackA->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current = current->next;
	current->next = stackA->head;
	stackA->head = current;
}

void	ft_rrb(t_stack* stackB)
{
	if (!stackB || !stackB->head || !stackB->head->next)
		return;
	node* prev = NULL;
	node* current = stackB->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current = current->next;
	current->next = stackB->head;
	stackB->head = current;
}

void	ft_rrr(t_stack* stackA, t_stack* stackB)
{
	ft_rra(stackA);
	ft_rrb(stackB);
}
