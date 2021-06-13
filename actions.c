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

//----------------------ACTIONS--------------------//

void	swap_firstwo(t_nbr *head)
{
	head->nbr = head->nbr + head->next->nbr;				// a = a + b // 5 = 5 + 4 => 9
	head->next->nbr = head->nbr - head->next->nbr;			// b = a - b => (a + b) - b // 4 = 9 - 4 => 5
	head->nbr = head->nbr - head->next->nbr;				// 5 + 4 = 9 || 9 - 4 = 5 || 9 - 5 = 4
	printf("action\n");
}

void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b)
{
	swap_firstwo(stack_a);
	swap_firstwo(stack_b);
	printf("action\n");
}

void	rotate_stack(t_nbr *head)
{
	long		tmp;

	tmp = head->nbr;
	while(head->next != NULL)
	{
		head->nbr = head->next->nbr;
		head->next->nbr = tmp;
		head = head->next;
	}
	printf("action\n");
}

void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	printf("action\n");
}

void	rev_rotate_stack(t_nbr *head)
{
	long		tmp;
	long		tmp2;
	t_nbr	*tail;

	tail = getlast_node(head);
	tmp2 = tail->nbr;
	tmp = head->next->nbr;
	head->next->nbr = head->nbr;
	head->nbr = tmp2;
	// printf("1===========> %ld\n", head->nbr);
	// printf("2===========> %ld\n", tail->nbr);
	head = head->next;
	while (head->next != NULL)
	{
		tmp2 = head->next->nbr;
		head->next->nbr = tmp;
		tmp = tmp2;
		head = head->next;
	}
	printf("action\n");
}

void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
	printf("action\n");
}

void	push_stacktop(t_nbr	**target, t_nbr **dst)
{
	if ((*dst) == NULL)
		add_node(dst, init_node((*target)->nbr));
	else	
		new_head(dst, init_node((*target)->nbr));
	remove_node(target, *target);
	printf("action\n");
}

//--------------------------------------------------//