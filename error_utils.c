/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:57:21 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/22 15:57:23 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr(char *str)
{
	int		i;

	i = 0;
    if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *str)
{
	int		nbr;
	int		nbr_len;

	nbr = 0;
	nbr_len = ft_strlen(str) - 1;
	if (ft_strncmp(str, "-1", nbr_len))
	{
		nbr = ft_atoi(str);
		if (nbr == -1)
			return (0);
	}
	return (1);
}

int	is_sorted(t_nbr *head)
{
	if (head)
	{
		while(head->next)
		{
			if (head->nbr > head->next->nbr)
				return (0);
			head = head->next;
		}
		return (1);
	}
	return (0);
}

int	find_dup(t_nbr *tmp, int nbr, int counter)
{
	while (tmp->next != NULL)
	{
		if (tmp->nbr == nbr)
			counter++;
		tmp = tmp->next;
	}
	if (tmp->nbr == nbr)
		counter++;
	return (counter);
}

int	is_duplicated(t_nbr *head)
{
	t_nbr	*tmp1;
	t_nbr	*tmp2;
	int		counter;

	tmp1 = head;
	while(tmp1->next != NULL)
	{
		tmp2 = tmp1;
		counter = 0;
		counter = find_dup(tmp2, tmp1->nbr, counter);
		if (counter > 1)
			return (1);
		tmp1 = tmp1->next;
	}
	tmp2 = tmp1;
	counter = 0;
	counter = find_dup(tmp2, tmp1->nbr, counter);
	if (counter > 1)
		return (1);
	return (0);
}
