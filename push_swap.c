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
				push_stacktop(head_b, head_a, "pb\n");
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

void	verify_push(t_nbr **head_a, t_nbr **head_b, int *buff, int range)
{
	int		i;
	int		key;
	t_nbr 	*tmp_a;

	i = 0;
	tmp_a = *head_a;
	while (tmp_a->next != NULL || stack_lenght(*head_b) < range)
	{
		key = 0;
		while (i < range)
		{
			if (tmp_a->nbr == buff[i++])
			{
				key = 1;
				rotat_push(head_a, head_b, get_pos(*head_a, tmp_a->nbr), "ra\n rra\n pa\n");
				if (stack_lenght(*head_b) == range)
					return ;
				tmp_a = *head_a;
				break ;
			}
		}
		i = 0;
		if (key == 0)
			tmp_a = tmp_a->next;
	}
}

void	sort_onehundred(t_nbr **head_a, t_nbr **head_b, int divisor)
{
	int		range;
	int		*buff;
	int		lenght;
	int		nbr;
	int		pos;

	nbr = 0;
	pos = 0;
	lenght = stack_lenght(*head_a);
	buff = ft_calloc(sizeof(int), lenght);
	fill_buff(*head_a, &buff);
	bubble_sort(&buff, lenght);
	range = lenght / divisor;
	while (stack_lenght(*head_b) < lenght)
	{
		verify_push(head_a, head_b, buff, range);
		range = inc(range, lenght, divisor);
	}
	while (stack_lenght(*head_a) < lenght)
	{
		nbr = bigest_nbr(*head_b);
		pos = get_pos(*head_b, nbr);
		rotat_push(head_b, head_a, pos, "rb\n rrb\n pb\n");
	}
}

//Don't even try to read this function just skip bro

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
			rotate_stack(*head_a, "rrb\n");
		}
		else
		{
			if (get_pos(*head_b, buff[bignbr]) > stack_lenght(*head_b))
				rotate_stack(*head_b, "rrb\n");
			else
				rev_rotate_stack(*head_b, "rb\n");
		}
	}
}

void	fill_back(t_nbr **head_a, t_nbr **head_b, int *buff)
{
	int		bignbr;

	while (stack_lenght(*head_b) > 0)
	{
		bignbr = get_nbrank(buff, bigest_nbr(*head_b), stack_lenght(*head_b));
		check_npush(head_a, head_b, buff, bignbr);
		if ((*head_a)->next && (*head_a)->nbr > (*head_a)->next->nbr)
			swap_firstwo((*head_a), "sb\n");
		if (getlast_node(*head_a)->nbr < buff[bignbr])
			rev_rotate_stack(*head_a, "ra\n");
	}
}

void	middpoint_algo(t_nbr **head_a, t_nbr **head_b, int divisor)
{
	int		*buff;
	int		lenght;
	int		middle;
	int		chunk_len;
	int		chunk;
	int		current_len;
	int		i;
	t_nbr	*tmp_a;

	tmp_a = *head_a;
	lenght = stack_lenght(*head_a);
	middle = (lenght / 2) - 1;
	chunk_len = lenght / divisor;
	buff = ft_calloc(sizeof(int), lenght);
	chunk = 1;
	fill_buff(*head_a, &buff);
	bubble_sort(&buff, lenght);
	while (stack_lenght((*head_a)) > 0)
	{
		i = 0;
		current_len = stack_lenght(*head_a);
		while (i < current_len)
		{
			if (tmp_a->nbr >= buff[middle - chunk_calc(chunk_len, chunk, lenght, -1)]
			&& tmp_a->nbr < buff[middle])
			{
				push_stacktop(head_a, head_b, "pa\n");
				rotate_stack((*head_b), "rrb\n");
			}
			else if (tmp_a->nbr <= buff[middle + chunk_calc(chunk_len, chunk, lenght, 1)]
			&& tmp_a->nbr >= buff[middle])
				push_stacktop(head_a, head_b, "pa\n");
			else
				rotate_stack((*head_a), "rra\n");
			if (current_len > 1)				
				tmp_a = *head_a;
			i++;
		}
		chunk++;
	}
	fill_back(head_a, head_b, buff);
}

void	sort_bigstack(t_nbr **stack_a, t_nbr **stack_b)
{
	if (stack_lenght(*stack_a) <= 100)
		middpoint_algo(stack_a, stack_b, 6);
	if (stack_lenght(*stack_a) > 100)
		middpoint_algo(stack_a, stack_b, 12);
	// if (stack_lenght(*stack_a) <= 100)
	// 	sort_onehundred(stack_a, stack_b, 6);
	// else if (stack_lenght(*stack_a) > 100)
	// 	sort_onehundred(stack_a, stack_b, 12);
}

void	sort_smallstack(t_nbr **stack_a, t_nbr **stack_b)
{
	(void)stack_b;

	if (stack_lenght(*stack_a) <= 3)
		sort_tree(*stack_a);
	else if (stack_lenght(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
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
	// printf("---------------------------------\n");
	// printf("Befor :\n");
	// print_list(stack_a);
	if (stack_lenght(stack_a) > 1)
	{
		if (stack_lenght(stack_a) <= 5)
			sort_smallstack(&stack_a, &stack_b);
		else if (stack_lenght(stack_a) > 5)
			sort_bigstack(&stack_a, &stack_b);
	}
	// printf("---------------------------------\n");
	// printf("After :\n");
	// print_list(stack_a);
	// printf("---------------------------------\n");
	// printf("lenght = %d\n", stack_lenght(stack_b));
    return (0);
}
