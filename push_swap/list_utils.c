
#include "push_swap.h"

node	*create_node(int value)
{
    node* newNode = (node*) malloc(sizeof(node));
	newNode->value = value;
	newNode->next = NULL;
	return (newNode);
}

node	*pop(t_stack* stack)
{
	node*	tmp;

	if (!stack || stack->head == NULL)
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	return (tmp);
}

void	insert_node_head(t_stack* stack, node* node)
{
	node*	tmp;

	if (!stack || !node)
		return;
	tmp = stack->head;
	stack->head = node;
	stack->head->next = tmp;
}

void	insert_node_tail(t_stack* stack, node* node)
{
	node*	current;

	if (!stack || !node)
		return;
	current = stack->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = node;
	node->next = NULL;
}

void	destroy_node(node* node)
{
	free(node);
}
