/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:45:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/23 13:07:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(int* parsed, int size)
{
    int i;
    t_stack stackA;
    t_stack stackB;
    
    ft_initialize_stack(&stackA);
    ft_initialize_stack(&stackB);
    i = 0;
    while (i < size)
    {
        if (!stackA.head)
            insert_node_head(&stackA, create_node(parsed[i]));
        else
            insert_node_tail(&stackA,create_node(parsed[i]));
        i++;
    }
    ft_sort_stack(&stackA, &stackB);
    //ft_print_stack(&stackA, 'a');
}

int main(int argc, char** argv)
{
    int size;
    int* parsed;
    
    if (argc > 1)
    {
        if (!ft_param_checker(argc, argv))
        {
            ft_printf("NON VALID ARGUMENTS\n");
        }
        else
        {
            ft_printf("VALID ARGUMENTS\n");
            if (argc == 2)
            {
                char** splited = ft_split(argv[1], ' ');
                size = ft_matrix_size(splited);
                parsed = ft_parse(splited, 0);
                push_swap(parsed, size);
                ft_free_matrix(splited);
            }
            else
            {
                size = (ft_matrix_size(argv) - 1);
                parsed = ft_parse(argv, 1);
                push_swap(parsed, size);
            }
        }
        free(parsed);
    }
    return 0;
}