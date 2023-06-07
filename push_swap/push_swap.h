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

#ifndef PUSH_SWAP.H
#define PUSH_SWAP.H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct node
{
    int	value;
	struct node* next;
}node;

typedef struct t_stack
{
	node*	head;
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

// list_utils
node	*create_node(int value);
node	*pop(t_stack* stack);
void	insert_node_head(t_stack* stack, node* node);
void	insert_node_tail(t_stack* stack, node* node);
void	destroy_node(node* node);
// utils
int		ft_is_sorted(int* values);
// param_aux_functions
int		ft_matrix_size(char** matrix);
void	ft_free_matrix(char** matrix);
int		is_space(char c);
int		ft_isdup(int* nb);
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