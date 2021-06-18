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

int		chunk_calc(int len, int chunk, int lenght, int m)
{
	int		res;

	res = len * chunk;
	if (res > (lenght / 2))
		res = lenght / 2;
	if (m < 0)
	{
		if (m + res > 0)
			res = m * -1;
	}
	return (res);
}

void	exit_error(int stream)
{
	ft_putstr_fd("error:\n", stream);
	exit(-1);
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

int		inc(int range, int lenght, int divisor)
{
	int		add;

	add = lenght / divisor;
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

void	rotat_call(t_nbr **target, int *pos, char **tag, int middle)
{
	if (*pos <= middle)
	{
		while (*pos > 1)
		{
			rotate_stack(*target, tag[0]);
			(*pos)--;
		}
	}
	else if (*pos > middle)
	{
		while (*pos <= stack_lenght(*target))
		{
			rev_rotate_stack(*target, tag[1]);
			(*pos)++;
		}
		*pos = 1;
	}
}

void	rotat_push(t_nbr **target, t_nbr **dst, int pos, char *tag)
{
	int		middle;
	char	**tagname;

	tagname = ft_split(tag, ' ');
	middle = stack_lenght(*target) / 2;
	if (pos > 1)
		rotat_call(target, &pos, tagname, middle);
	if (pos == 1)
		push_stacktop(target, dst, tagname[2]);
}
