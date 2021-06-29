/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:43:38 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/26 21:43:39 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_lenght(t_nbr *head)
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

int	get_pos(t_nbr *head, int nbr)
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

int	bigest_nbr(t_nbr *head)
{
	int		nbr;

	nbr = head->nbr;
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

int	chunk_calc(int len, int chunk, int lenght, int sign)
{
	int		res;

	res = len * chunk;
	if (res > (lenght / 2))
		res = lenght / 2;
	if (sign == -1 && res == (lenght / 2))
		res -= 1;
	return (res);
}
