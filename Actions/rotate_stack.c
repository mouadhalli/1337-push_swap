#include "../push_swap.h"

void	rev_rotate_stack(t_nbr *head, char *tag)
{
	long		tmp;
	long		tmp2;

	if (stack_lenght(head) > 1)
	{
		tmp2 = getlast_node(head)->nbr;
		tmp = head->next->nbr;
		head->next->nbr = head->nbr;
		head->nbr = tmp2;
		head = head->next;
		while (head->next != NULL)
		{
			tmp2 = head->next->nbr;
			head->next->nbr = tmp;
			tmp = tmp2;
			head = head->next;
		}
	}
	ft_putstr_fd(tag, 1);
}

void	rotate_stack(t_nbr *head, char *tag)
{
	long		tmp;

	tmp = head->nbr;
	while(head->next != NULL)
	{
		head->nbr = head->next->nbr;
		head->next->nbr = tmp;
		head = head->next;
	}
	ft_putstr_fd(tag, 1);
}

void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rev_rotate_stack(stack_a, "rra\n");
	rev_rotate_stack(stack_b, "rrb\n");
	ft_putstr_fd("rrr\n", 1);
}

void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rotate_stack(stack_a, "ra");
	rotate_stack(stack_b, "rb");
	ft_putstr_fd("rr\n", 1);
}
