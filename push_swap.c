/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:18:07 by mhalli            #+#    #+#             */
/*   Updated: 2021/05/29 15:18:09 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		rotat_push(head_a, head_b, pos, "ra\n rra\n pa\n");
		if (stack_lenght(*head_a) == 3)
		{
			sort_tree(*head_a);
			while (stack_lenght(*head_b) > 0)
				push_stacktop(head_b, head_a, "pa\n");
			break;
		}
	}
}

void	bubble_sort(int	**buff, int lenght)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (j < lenght - 1)
	{
		while (i < lenght - j -1)
		{
			if ((*buff)[i] > (*buff)[i + 1])
			{
				tmp = (*buff)[i];
				(*buff)[i] = (*buff)[i + 1];
				(*buff)[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

// AND THIS IS WHAT WE CALL A SPAGHETI CODE

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
		bignbr = get_nbrank((*stack)->tab, bigest_nbr((*stack)->b),
			stack_lenght((*stack)->b));
		check_npush(&(*stack)->a, &(*stack)->b, (*stack)->tab, bignbr);
		if ((*stack)->a->next && (*stack)->a->nbr > (*stack)->a->next->nbr)
			swap_firstwo((*stack)->a, "sa\n");
		if (getlast_node((*stack)->a)->nbr < (*stack)->tab[bignbr])
			rev_rotate_stack((*stack)->a, "rra\n");
	}
}

void	push_rotate(t_stack **stack, int lenght, int div, int chunk)
{

	if ((*stack)->a->nbr >= (*stack)->tab[get_index(lenght, div, chunk, -1)]
	&& ((*stack)->a->nbr < (*stack)->tab[(lenght / 2) - 1]))
	{
		push_stacktop(&(*stack)->a, &(*stack)->b, "pb\n");
		rotate_stack((*stack)->b, "rb\n");
	}
	else if ((*stack)->a->nbr <= (*stack)->tab[get_index(lenght, div, chunk, 1)]
	&& ((*stack)->a->nbr >= (*stack)->tab[(lenght / 2) - 1]))
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
	(*stack)->tab = init_buff((*stack)->tab, (*stack)->a, lenght);
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

void	sort_smallstack(t_stack **stack)
{
	if (stack_lenght((*stack)->a) <= 3)
		sort_tree((*stack)->a);
	else if (stack_lenght((*stack)->a) <= 5)
		sort_five(&(*stack)->a, &(*stack)->b);
}

t_stack *stack_constructor(t_stack *stack, int argc, char **argv)
{
	int		i;

	i = 0;
	// filter_input(argv);
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	while (++i < argc)
	{
		if (!is_nbr(argv[i]) || !is_int(argv[i]))
            exit_error(2);
		add_node(&stack->a, init_node(ft_atoi(argv[i])));
	}
	return (stack);
}

void	stack_checker(t_stack *stack)
{
	if (is_sorted(stack->a))
		exit(1);
	if (is_duplicated(stack->a))
		exit_error(2);
}

int     main(int argc, char **argv)
{
	t_stack		*stack;
    int     i;

    i = 0;
	stack = NULL;
	stack = stack_constructor(stack, argc, argv);
	stack_checker(stack);
    // while (++i < argc)
        // add_node(&stack->a, init_node(ft_atoi(argv[i])));
	// printf("---------------------------------\n");
	// printf("Befor :\n");
	// print_list(stack_a);
	// if (stack_lenght(stack->a) > 1)
	// {
	// 	if (stack_lenght(stack->a) <= 5)
	// 		sort_smallstack(&stack);
	// 	else if (stack_lenght(stack->a) > 5)
	// 		sort_bigstack(&stack);
	// }
	printf("---------------------------------\n");
	printf("After :\n");
	print_list(stack->a);
	printf("---------------------------------\n");
	// printf("lenght = %d\n", stack_lenght(stack->a));
    return (0);
}
