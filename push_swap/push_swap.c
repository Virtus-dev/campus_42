

node	*create_node(int value)
{
    node* newNode = (node*) malloc(sizeof(node));
	newNode->value = value;
	newNode->next = NULL;
	return (newNode);
}

node	*pop(t_stack* stack)
{
	if (!stack || stack->head == NULL)
	node* tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	return (tmp);
}

void	insert_node_head(t_stack* stack, node* node)
{
	if (!stack || !node)
		return;
	node* tmp = stack->head;
	stack->head = node;
	stack->head->next = tmp;
}

void	insert_node_tail(t_stack* stack, node* node)
{
	if (!stack || !node)
		return;
	node* current = stack->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = node;
	//node->next = NULL;
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

void	ft_rr(t_satck* stackA, t_stack* stackB)
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

void	ft_rrr(t_satck* stackA, t_stack* stackB)
{
	ft_rra(stackA);
	ft_rrb(stackB);
}

void destroy_node(node* node)
{
	free(node);
}

