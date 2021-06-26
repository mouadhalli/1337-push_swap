/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:47:06 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/26 21:47:09 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (tag)
		ft_putstr_fd(tag, 1);
}

void	rotate_stack(t_nbr *head, char *tag)
{
	long		tmp;

	if (head)
	{
		tmp = head->nbr;
		while (head->next != NULL)
		{
			head->nbr = head->next->nbr;
			head->next->nbr = tmp;
			head = head->next;
		}
		if (tag)
			ft_putstr_fd(tag, 1);
	}
}

void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b, int key)
{
	if (stack_a && stack_b)
	{
		if (key)
		{
			rev_rotate_stack(stack_a, "rra\n");
			rev_rotate_stack(stack_b, "rrb\n");
			ft_putstr_fd("rrr\n", 1);
		}
		else
		{
			rev_rotate_stack(stack_a, NULL);
			rev_rotate_stack(stack_b, NULL);
		}
	}
}

void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b, int key)
{
	if (stack_a && stack_b)
	{
		if (key)
		{
			rotate_stack(stack_a, "ra\n");
			rotate_stack(stack_b, "rb\n");
			ft_putstr_fd("rr\n", 1);
		}
		else
		{
			rotate_stack(stack_a, NULL);
			rotate_stack(stack_b, NULL);
		}
	}
}

void	exec_rotate(t_stack *stack, char *action)
{
	if (ft_strlen(action) == 2)
	{
		if (action[1] == 'a')
			rotate_stack(stack->a, NULL);
		else if (action[1] == 'b')
			rotate_stack(stack->b, NULL);
		else if (action[1] == 'r')
			rotate_ab(stack->a, stack->b, 0);
	}
	else if (ft_strlen(action) == 3)
	{
		if (action[2] == 'a')
			rev_rotate_stack(stack->a, NULL);
		else if (action[2] == 'b')
			rev_rotate_stack(stack->b, NULL);
		else if (action[2] == 'r')
			rev_rotate_ab(stack->a, stack->b, 0);
	}
}
