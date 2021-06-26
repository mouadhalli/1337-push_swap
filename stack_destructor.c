
#include "push_swap.h"

void	exit_error(int stream, t_stack *stack, int key)
{
    if (key)
	    ft_putstr_fd("Error\n", stream);
    stack_destructor(stack);
	exit(-1);
}

void	free_list(t_nbr **list)
{
	t_nbr	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

t_stack	*stack_destructor(t_stack *stack)
{
	if (stack)
	{
		free_list(&stack->a);
		free_list(&stack->b);
        if (stack->arr)
		    free(stack->arr);
		free(stack);
	}
	return (NULL);
}