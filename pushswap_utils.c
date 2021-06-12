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

int		decrement(int range, int lenght)
{
	int		substract;

	substract = lenght / 6;
	range -= substract;
	if (range < 0)
		range = 0;
	return (range);
}

int		inc(int range, int lenght)
{
	int		add;

	add = lenght / 6;
	if (lenght > 150)
		add = lenght / 12;
	range += add;
	if (range > lenght)
		range = lenght;
	return (range);
}

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

void	rotat_push(t_nbr **target, t_nbr **dst, int pos)
{
	int		middle;

	middle = stack_lenght(*target) / 2;
	if (pos > 1)
	{
		if (pos <= middle)
		{
			while (pos > 1)
			{
				rotate_stack(*target);
				pos--;
			}
		}
		else if (pos > middle)
		{
			while (pos <= stack_lenght(*target))
			{
				rev_rotate_stack(*target);
				pos++;
			}
			pos = 1;
		}
	}
	if (pos == 1)
		push_stacktop(target, dst);
}