/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:51:21 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/26 21:51:22 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_checker(t_stack *stack, int is_checker)
{
	if (stack->a == NULL)
		exit_error(2, stack, 0);
	if (stack_lenght(stack->a) == 1)
		return ;
	if (is_duplicated(stack->a))
		exit_error(2, stack, 1);
	if (!is_checker && is_sorted(stack->a))
		exit_error(2, stack, 0);
}

t_nbr	*getlast_node(t_nbr *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

t_nbr	*init_node(long nbr)
{
	t_nbr	*node;

	node = (t_nbr *)malloc(sizeof(t_nbr));
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	add_node(t_nbr **head, t_nbr *new_node)
{
	t_nbr	*tail;

	if (*head == NULL)
		*head = new_node;
	else
	{
		tail = getlast_node(*head);
		tail->next = new_node;
	}
}

t_stack	*stack_constructor(t_stack *stack, int input_len, char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	stack->arr = NULL;
	while (++i < input_len)
	{
		j = 0;
		input = ft_split(argv[i], ' ');
		while (input[j])
		{
			if (!is_nbr(input[j]) || !is_int(input[j]))
				exit_error(2, stack, 1);
			add_node(&stack->a, init_node(ft_atoi(input[j++])));
			free_arr(input);
		}
	}
	return (stack);
}
