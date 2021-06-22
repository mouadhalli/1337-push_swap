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

#include "push_swap.h"

void	swap_firstwo(t_nbr *head, char *tag)
{
	if (stack_lenght(head) > 1)
	{
		head->nbr = head->nbr + head->next->nbr;
		head->next->nbr = head->nbr - head->next->nbr;
		head->nbr = head->nbr - head->next->nbr;
		ft_putstr_fd(tag, 1);
	}
}

void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b)
{
	swap_firstwo(stack_a, "sa");
	swap_firstwo(stack_b, "sb");
	ft_putstr_fd("ss\n", 1);
}

void	rotate_stack(t_nbr *head, char *tag)
{
	long		tmp;

	tmp = head->nbr;
	while(head->next != NULL)
	{
		head->nbr = head->next->nbr;
		head->next->nbr = tmp;
		head = head->next;
	}
	ft_putstr_fd(tag, 1);
}

void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rotate_stack(stack_a, "ra");
	rotate_stack(stack_b, "rb");
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_stack(t_nbr *head, char *tag)
{
	long		tmp;
	long		tmp2;
	t_nbr	*tail;

	if (stack_lenght(head) > 1)
	{
		tail = getlast_node(head);
		tmp2 = tail->nbr;
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
	ft_putstr_fd(tag, 1);
}

void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rev_rotate_stack(stack_a, "rra\n");
	rev_rotate_stack(stack_b, "rrb\n");
	ft_putstr_fd("rrr\n", 1);
}

void	push_stacktop(t_nbr	**target, t_nbr **dst, char *tag)
{
	if (stack_lenght(*target) > 0)
	{
		if ((*dst) == NULL)
			add_node(dst, init_node((*target)->nbr));
		else	
			new_head(dst, init_node((*target)->nbr));
		remove_node(target, *target);
		ft_putstr_fd(tag, 1);
	}
}
