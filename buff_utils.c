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

int		get_index(int lenght, int divisor, int chunk , int sign)
{
	int		middle;
	int		len;
	int		ret;

	middle = (lenght / 2) -1;
	len = lenght / divisor;
	if (sign == -1)
		ret = middle - chunk_calc(len, chunk, lenght, -1);
	else
		ret = middle + chunk_calc(lenght / divisor, chunk, lenght, 1);
	return (ret);
}

int		*init_buff(int *buff, t_nbr *content, int lenght)
{
	buff = ft_calloc(sizeof(int), lenght);
	fill_buff(content, &buff);
	bubble_sort(&buff, lenght);
	return (buff);
}

int		get_nbrank(int *buff, int nbr, int lenght)
{
	int		i;

	i = -1;
	while (++i < lenght)
	{
		if (nbr == buff[i])
			return (i);
	}
	return (i);
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
