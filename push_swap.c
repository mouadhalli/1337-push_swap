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

void	exit_error(int stream)
{
	ft_putstr_fd("error:\n", stream);
	exit(-1);
}

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
				rotate_stack(head);
			else if (pos == 2)
				rev_rotate_stack(head);
		}
	}
	if (head->nbr > head->next->nbr)
		swap_firstwo(head);
}

void	sort_five(t_nbr **head_a, t_nbr **head_b)
{
	int		nbr;
	int		pos;

	while (stack_lenght(*head_a) >= 3)
	{
		nbr = small_nbr(*head_a);
		pos = get_pos(*head_a, nbr);
		rotat_push(head_a, head_b, pos);
		if (stack_lenght(*head_a) == 3)
		{
			sort_tree(*head_a);
			while (stack_lenght(*head_b) > 0)
				push_stacktop(head_b, head_a);
			break;
		}
	}
}

void	sort_smallstack(t_nbr **stack_a, t_nbr **stack_b)
{
	(void)stack_b;

	if (stack_lenght(*stack_a) <= 3)
		sort_tree(*stack_a);
	else if (stack_lenght(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
}

void	sort_onehundred(t_nbr **stack_a, t_nbr **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
void	sort_bigstack(t_nbr **stack_a, t_nbr **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

int     main(int argc, char **argv)
{
    t_nbr *stack_a;
    t_nbr *stack_b;
    int     i;

    i = 0;
    stack_a = NULL;
    stack_b = NULL;
	if (argc < 2)
		exit_error(1);
    while (++i < argc)
        add_node(&stack_a, init_node(ft_atoi(argv[i])));
	printf("---------------------------------\n");
	printf("Befor :\n");
	print_list(stack_a);
	if (stack_lenght(stack_a) > 1)
	{
		if (stack_lenght(stack_a) <= 5)
			sort_smallstack(&stack_a, &stack_b);
		else if (stack_lenght(stack_a) > 5)
			sort_bigstack(&stack_a, &stack_b);
	}
	// int test = stack_lenght(stack_b);
	// printf("===========>%d\n", test);
	printf("---------------------------------\n");
	printf("After :\n");
	print_list(stack_a);
	printf("---------------------------------\n");
    return (0);
}