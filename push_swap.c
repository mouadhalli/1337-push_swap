/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:18:07 by mhalli            #+#    #+#             */
/*   Updated: 2021/05/29 15:18:09 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr    *init_node(int nbr, char *nbr_str)
{
    t_nbr *node;

    node = (t_nbr *)malloc(sizeof(t_nbr));
    node->nbr = nbr;
    node->nbr_str = nbr_str;
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

void	printf_list(t_nbr *head)
{
	while (head->next != NULL)
	{
		printf("%d\n", head->nbr);
		head = head->next;
	}
	printf("%d\n", head->nbr);
}

void	exit_error(char *err_msg, int stream)
{
	ft_putstr_fd("error:\n", stream);
	ft_putstr_fd(err_msg, stream);
	exit(-1);
}

int     main(int argc, char **argv)
{
    t_nbr *head;
    int     i;

    i = 0;
    head = NULL;
	if (argc < 2)
		exit_error("no numbers to sort\n", 1);
    while (++i < argc)
        add_node(&head, init_node(ft_atoi(argv[i]), ft_strdup(argv[i])));
	printf_list(head);
    return (0);
}