/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:48:43 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/04 17:48:46 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_firstwo(t_nbr *head, char *tag)
{
	if (stack_lenght(head) > 1)
	{
		head->nbr = head->nbr + head->next->nbr;
		head->next->nbr = head->nbr - head->next->nbr;
		head->nbr = head->nbr - head->next->nbr;
		if (tag)
			ft_putstr_fd(tag, 1);
	}
}

void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b, int key)
{
	if (stack_a && stack_b)
	{
		if (key)
		{
			swap_firstwo(stack_a, "sa\n");
			swap_firstwo(stack_b, "sb\n");
			ft_putstr_fd("ss\n", 1);
		}
		else
		{
			swap_firstwo(stack_a, NULL);
			swap_firstwo(stack_b, NULL);
		}
	}
}

void	exec_swap(t_stack *stack, char *action)
{
	if (action[1] == 'a')
		swap_firstwo(stack->a, NULL);
	else if (action[1] == 'b')
		swap_firstwo(stack->b, NULL);
	else if (action[1] == 's')
		swap_a_b(stack->a, stack->b, 0);
}
