/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:12:43 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/07 21:12:46 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_lenght(t_nbr *head)
{
	int		lenght;

	lenght = 1;

	if (!head)
		return (0);
	while (head->next != NULL)
	{
		lenght++;
		head = head->next;
	}
	return (lenght);
}

int		get_pos(t_nbr *head, int nbr)
{
	int		pos;

	pos = 1;
	while (head->next != NULL)
	{
		if (head->nbr == nbr)
			return (pos);
		pos++;
		head = head->next;
	}
	return (pos);
}

// int		get_index(t_nbr *head, int nbr)
// {
//     int     pos;

//     pos = 0;
//     while (head->next != NULL)
//     {
//         if(head->nbr == nbr)
//             return(pos);
//         head = head->next;
//     }
//     return (pos);
// }

int		bigest_nbr(t_nbr *head)
{
	int		nbr;

	nbr = 0;
	while (head->next != NULL)
	{
		if (head->nbr > nbr)
			nbr = head->nbr;
		head = head->next;
	}
	if (head->nbr > nbr)
		nbr = head->nbr;
	return (nbr);
}

int		small_nbr(t_nbr *head)
{
	long		nbr;

	nbr = head->nbr;
	while (head->next != NULL)
	{
		if (head->nbr < nbr )
			nbr = head->nbr;
		head = head->next;
	}
	if (head->nbr < nbr)
		nbr = head->nbr;
	return (nbr);
}

void	rotat_push(t_nbr **head_a, t_nbr **head_b, int pos)
{
	int		middle;

	middle = stack_lenght(*head_a) / 2;
	if (pos > 1)
	{
		if (pos <= middle)
		{
			while (pos > 1)
			{
				rotate_stack(*head_a);
				pos--;
			}
		}
		else if (pos > middle)
		{
			while (pos <= stack_lenght(*head_a))
			{
				rev_rotate_stack(*head_a);
				pos++;
			}
			pos = 1;
		}
	}
	if (pos == 1)
		push_stacktop(head_a, head_b);
}