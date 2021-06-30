/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:51:27 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/26 21:51:29 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(int stream, t_stack *stack, int key, int status)
{
	if (key)
		ft_putstr_fd("Error\n", stream);
	stack_destructor(stack);
	exit(status);
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
