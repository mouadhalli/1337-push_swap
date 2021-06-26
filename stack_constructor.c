#include "push_swap.h"

void	stack_checker(t_stack *stack)
{
		if (stack->a == NULL)
			exit_error(2, stack, 0);
		if (stack_lenght(stack->a) == 1)
			return;
		if (is_duplicated(stack->a))
			exit_error(2, stack, 1);
		if (is_sorted(stack->a))
			exit_error(2, stack, 0);
}

t_nbr    *getlast_node(t_nbr *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    return (head);
}

t_nbr    *init_node(long nbr)
{
    t_nbr *node;

    node = (t_nbr *)malloc(sizeof(t_nbr));
    node->nbr = nbr;
    node->next = NULL;
    return (node);
}

void    add_node(t_nbr **head, t_nbr *new_node)
{
	t_nbr *tail;
	if (*head == NULL)
		*head = new_node;
	else
	{
		tail = getlast_node(*head);
    	tail->next = new_node;
	}
}

t_stack *stack_constructor(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		lenght;

	i = -1;
	lenght = argc - 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
    stack->arr = NULL;
	while (++i < lenght)
	{
		if (!is_nbr(argv[i + 1]) || !is_int(argv[i + 1]))
            exit_error(2, stack, 1);
		add_node(&stack->a, init_node(ft_atoi(argv[i + 1])));
	}
	return (stack);
}
