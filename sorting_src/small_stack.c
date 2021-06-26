#include "../push_swap.h"

void	sort_tree(t_nbr *head)
{
	int		bignbr;
	int		pos;

	if (stack_lenght(head) == 3)
	{
		bignbr = bigest_nbr(head);
 		pos = get_pos(head, bignbr);
		if (pos < 3)
		{
			if (pos == 1)
				rotate_stack(head, "ra\n");
			else if (pos == 2)
				rev_rotate_stack(head, "rra\n");
		}
	}
	if (head->nbr > head->next->nbr)
		swap_firstwo(head, "sa\n");
}

void	sort_five(t_nbr **head_a, t_nbr **head_b)
{
	int		nbr;
	int		pos;

	while (stack_lenght(*head_a) >= 3)
	{
		nbr = small_nbr(*head_a);
		pos = get_pos(*head_a, nbr);
		rotat_push(head_a, head_b, pos, "rb\n rrb\n pb\n");
		if (stack_lenght(*head_a) == 3)
		{
			sort_tree(*head_a);
			while (stack_lenght(*head_b) > 0)
				push_stacktop(head_b, head_a, "pa\n");
			break;
		}
	}
}

void	sort_smallstack(t_stack **stack)
{
	if (stack_lenght((*stack)->a) <= 3)
		sort_tree((*stack)->a);
	else if (stack_lenght((*stack)->a) <= 5)
		sort_five(&(*stack)->a, &(*stack)->b);
}