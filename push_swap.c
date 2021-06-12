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

void	fill_buff(t_nbr *head, int **buff)
{
	int		i;

	i = 0;
	while (head->next != NULL)
	{
		(*buff)[i++] = head->nbr;
		head = head->next;
	}
	(*buff)[i] = head->nbr;

}

void	bubble_sort(int	**buff, int lenght)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < lenght - 1)
	{
		while (i < lenght - j -1)
		{
			if ((*buff)[i] > (*buff)[i + 1])
			{
				(*buff)[i] = (*buff)[i] + (*buff)[i + 1];
				(*buff)[i + 1] = (*buff)[i] - (*buff)[i + 1];
				(*buff)[i] = (*buff)[i] - (*buff)[i + 1];
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	verify_push_a(t_nbr **head_a, t_nbr **head_b, int *buff, int range)
{
	int		i;
	t_nbr 	*tmp_a;

	i = 0;
	tmp_a = *head_a;
	while (tmp_a->next != NULL)
	{
		while (i < range)
		{
			if (tmp_a->nbr == buff[i++])
			{
				rotat_push(head_a, head_b, get_pos(*head_a, tmp_a->nbr));
				break;
			}
		}
		i = 0;
		tmp_a = tmp_a->next;
	}
	while (i < range)
	{
		if (tmp_a->nbr == buff[i++])
		{
			rotat_push(head_a, head_b, get_pos(*head_a, tmp_a->nbr));
			break;
		}
	}
}

// void	verify_push_b(t_nbr **head_a, t_nbr **head_b, int *buff, int range)
// {
// 	int		i;
// 	t_nbr 	*tmp_b;

// 	i = 100;
// 	tmp_b = *head_b;
// 	while (tmp_b->next != NULL)
// 	{
// 		while (i >= range)
// 		{
// 			if (tmp_b->nbr == buff[i--])
// 			{
// 				rotat_push(head_b, head_a, get_pos(*head_b, tmp_b->nbr));
// 				break;
// 			}
// 		}
// 		i = 100;
// 		tmp_b = tmp_b->next;
// 	}
// 	while (i >= range)
// 	{
// 		if (tmp_b->nbr == buff[i--])
// 		{
// 			rotat_push(head_b, head_a, get_pos(*head_b, tmp_b->nbr));
// 			break;
// 		}
// 	}
// }

void	sort_onehundred(t_nbr **head_a, t_nbr **head_b)
{
	(void)head_b;
	int		range;
	int		*buff;
	int		lenght;

	lenght = stack_lenght(*head_a);
	buff = ft_calloc(sizeof(int), lenght);
	fill_buff(*head_a, &buff);
	bubble_sort(&buff, lenght);
	range = lenght / 6;
	while (stack_lenght(*head_b) < lenght)
	{
		verify_push_a(head_a, head_b, buff, range);
		range = inc(range, lenght);
	}
	// range = decrement(range, lenght);
	// while (stack_lenght(*head_a) < lenght)
	// {
	// 	verify_push_b(head_a, head_b, buff, range);
	// 	range = decrement(range, lenght);
	// }
}


void	sort_bigstack(t_nbr **stack_a, t_nbr **stack_b)
{
	if (stack_lenght(*stack_a) == 100)
		sort_onehundred(stack_a, stack_b);
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
	// printf("lenght = %d\n", stack_lenght(stack_a));
    return (0);
}