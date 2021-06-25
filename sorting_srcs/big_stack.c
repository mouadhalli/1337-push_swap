
#include "../push_swap.h"

void	check_npush(t_nbr **head_a, t_nbr **head_b, int *buff, int bignbr)
{
	while (1)
	{
		if ((*head_b)->nbr == buff[bignbr])
		{
			push_stacktop(head_b, head_a, "pa\n");
			break;
		}
		else if ((*head_b)->nbr == buff[bignbr - 1])
			push_stacktop(head_b, head_a, "pa\n");
		else if ((*head_b)->nbr == buff[bignbr - 2])
		{
			push_stacktop(head_b, head_a, "pa\n");
			rotate_stack(*head_a, "ra\n");
		}
		else
			if (get_pos(*head_b, buff[bignbr]) > stack_lenght(*head_b) / 2)
				rev_rotate_stack(*head_b, "rrb\n");
			else
				rotate_stack(*head_b, "rb\n");
	}
}

void	fill_back(t_stack **stack)
{
	int		bignbr;
	int		lenght;

	while (stack_lenght((*stack)->b) > 0)
	{
		lenght = stack_lenght((*stack)->b);
		bignbr = get_nbrank((*stack)->arr, bigest_nbr((*stack)->b),
			stack_lenght((*stack)->b));
		check_npush(&(*stack)->a, &(*stack)->b, (*stack)->arr, bignbr);
		if ((*stack)->a->next && (*stack)->a->nbr > (*stack)->a->next->nbr)
			swap_firstwo((*stack)->a, "sa\n");
		if (getlast_node((*stack)->a)->nbr < (*stack)->arr[bignbr])
			rev_rotate_stack((*stack)->a, "rra\n");
	}
}

void	push_rotate(t_stack **stack, int lenght, int div, int chunk)
{

	if ((*stack)->a->nbr >= (*stack)->arr[get_index(lenght, div, chunk, -1)]
	&& ((*stack)->a->nbr < (*stack)->arr[(lenght / 2) - 1]))
	{
		push_stacktop(&(*stack)->a, &(*stack)->b, "pb\n");
		rotate_stack((*stack)->b, "rb\n");
	}
	else if ((*stack)->a->nbr <= (*stack)->arr[get_index(lenght, div, chunk, 1)]
	&& ((*stack)->a->nbr >= (*stack)->arr[(lenght / 2) - 1]))
		push_stacktop(&(*stack)->a, &(*stack)->b, "pb\n");
	else
		rotate_stack((*stack)->a, "ra\n");
}

void	middpoint_algo(t_stack **stack, int divisor)
{
	int		lenght;
	int		current_len;
	int		chunk;
	int		i;

	lenght = stack_lenght((*stack)->a);
	chunk = 1;
	(*stack)->arr = init_buff((*stack)->arr, (*stack)->a, lenght);
	while (stack_lenght((*stack)->a) > 0)
	{
		i = -1;
		current_len = stack_lenght((*stack)->a);
		while (++i < current_len)
			push_rotate(stack, lenght, divisor, chunk);
		chunk++;
	}
	fill_back(stack);
}

void	sort_bigstack(t_stack **stack)
{
	if (stack_lenght((*stack)->a) <= 100)
		middpoint_algo(stack, 6);
	if (stack_lenght((*stack)->a) > 100)
		middpoint_algo(stack, 18);
}