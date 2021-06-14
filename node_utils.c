/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:49:59 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/04 17:50:01 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr    *init_node(long nbr)
{
    t_nbr *node;

    node = (t_nbr *)malloc(sizeof(t_nbr));
    node->nbr = nbr;
    node->next = NULL;
    return (node);
}

t_nbr    *getlast_node(t_nbr *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    return (head);
}

void    add_node(t_nbr **head, t_nbr *new_node)
{
	t_nbr *tail;
	if (*head == NULL)
		*head = new_node;
	else
	{
		tail = getlast_node(*head);
    	tail->next = new_node;
	}
}

void	free_node(t_nbr *node)
{
	free(node);
}

void	remove_middlast(t_nbr *tmp, t_nbr *target)
{
	t_nbr *left;
	t_nbr *right;

	while (tmp->next != NULL)
	{
		if (target == tmp->next)
		{
			left = tmp;
			tmp = tmp->next;
			right = tmp->next;
			free_node(tmp);
			left->next = right;
			break;
		}
		tmp = tmp->next;
	}
}

void	remove_node(t_nbr **head, t_nbr *target)
{
	t_nbr *tmp;

	tmp = *head;
	if (target == tmp)
	{
		(*head) = tmp->next;
		free_node(tmp);
	}
	else
		remove_middlast(tmp, target);
}

void	new_head(t_nbr **oldhead, t_nbr *newhead)
{
	newhead->next = *oldhead;
	(*oldhead) = newhead;
}

void	print_list(t_nbr *head)
{
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			printf("nbr == %ld\n", head->nbr);
			head = head->next;
		}
		printf("nbr == %ld\n", head->nbr);
	}
}

