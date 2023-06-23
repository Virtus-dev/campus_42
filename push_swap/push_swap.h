/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:00:30 by arigonza          #+#    #+#             */
/*   Updated: 2023/04/19 23:00:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

typedef struct Node
{
    int	value;
	struct Node* next;
}Node;

typedef struct t_stack
{
	Node*	head;
	int		size;
}t_stack;

//Colors Start
# define FRED "\033[0;31m"
# define FGREEN "\033[0;32m"
# define FYELLOW "\033[0;33m"
# define FBLUE "\033[0;34m"
# define FPURPLE "\033[0;35m"
# define NONE "\033[0;37m"
//Colors End
//void	ft_radix_sort(t_stack* stackA, t_stack* stackB);
void	ft_sort_stack(t_stack* stackA, t_stack* stackB);
// list_utils
Node	*create_node(int value);
Node	*pop(t_stack* stack);
void	insert_node_head(t_stack* stack, Node* node);
void	insert_node_tail(t_stack* stack, Node* node);
void	destroy_node(Node* node);
// utils
int		ft_is_sorted(int* values, int size);
void	ft_print_stack(t_stack* stack, char c);
int		get_max_value(t_stack* stack);
void	ft_initialize_stack(t_stack* stack);
// argv_checker
int		ft_param_checker(int argc, char** argv);
int		*ft_parse(char** splited, int argc);
// param_aux_functions
int		ft_matrix_size(char** matrix);
void	ft_free_matrix(char** matrix);
int		ft_isdup(char** argv);
int		ft_is_nbr(char* s);
// swap operations
void	ft_sa(t_stack* stackA);
void	ft_sb(t_stack* stackB);
void	ft_ss(t_stack* stackA, t_stack* stackB);
// push operations
void	ft_pa(t_stack* stackA, t_stack* stackB);
void	ft_pb(t_stack* stackB, t_stack* stackA);
// rotate operations
void	ft_ra(t_stack* stackA);
void	ft_rb(t_stack* stackB);
void	ft_rr(t_stack* stackA, t_stack* stackB);
// reverse rotate operations
void	ft_rra(t_stack* stackA);
void	ft_rrb(t_stack* stackB);
void	ft_rrr(t_stack* stackA, t_stack* stackB);

#endif