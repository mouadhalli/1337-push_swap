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

void	exit_error(int stream)
{
	ft_putstr_fd("error:\n", stream);
	exit(-1);
}

int		get_index(t_nbr *head, int nbr)
{
	int		i;

	i = 0;
	while (head->next != NULL)
	{
		if (head->nbr == nbr)
			break;
		i++;
		head = head->next;
	}
	return (i);
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
	int		nbr;

	nbr = head->nbr;
	while (head->next != NULL)
	{
		if (head->nbr < nbr)
			nbr = head->nbr;
		head = head->next;
	}
	if (head->nbr < nbr)
		nbr = head->nbr;
	return (nbr);
}

void	oh_baby_its_triple(t_nbr *head)
{
	int		bignbr;
	int		index;

	bignbr = bigest_nbr(head);
	index = get_index(head, bignbr);
	if (index < 2)
	{
		if (index == 0)
			rotate_stack(head);
		else if (index == 1)
			rev_rotate_stack(head);
	}
	if (head->nbr > head->next->nbr)
		swap_firstwo(head);
}

void	rotat_push(t_nbr *head_a, t_nbr *head_b, int index)
{
	if (index > 0)
	{
		if (index <= 2)
		{
			while (index)
			{
				rotate_stack(head_a);
				index--;
			}
		}
		else if (index > 2)
		{
			while (index < 5)
			{
				rev_rotate_stack(head_a);
				index++;
			}
			index = 0;
		}
	}
	if (index == 0)
		push_stacktop(head_a, head_b);
}

void	sort_five(t_nbr *head_a, t_nbr *head_b)
{
	int		nbr;
	int		index;
	int		i;

	i = -1;
	while (++i < 2)
	{
		nbr = small_nbr(head_a);
		index = get_index(head_a, nbr);
		rotat_push(head_a, head_b, index);
	}
}

void	sort_smallstack(t_nbr *stack_a, t_nbr *stack_b)
{
	(void)stack_b;

	if (stack_a->detls.lenght  == 3)
		oh_baby_its_triple(stack_a);
	if (stack_a->detls.lenght == 5)
		sort_five(stack_a, stack_b);
}

int     main(int argc, char **argv)
{
    t_nbr *stack_a;
    t_nbr *stack_b;
    int     i;

    i = 0;
    stack_a = NULL;
    stack_b = NULL;
	if (argc < 2)
		exit_error(1);
    while (++i < argc)
	{
        add_node(&stack_a, init_node(ft_atoi(argv[i])));
        add_node(&stack_b, init_node(INT_MAX));
	}
	stack_a->detls.lenght = argc - 1;
	printf("---------------------------------\n");
	printf("Befor :\n");
	print_list(stack_a);
	if (stack_a->detls.lenght <= 5)
		sort_smallstack(stack_a, stack_b);
	// rotate_stack(stack_a);
	// rev_rotate_stack(stack_a);
	// swap_firstwo(stack_a);
	printf("---------------------------------\n");
	printf("After :\n");
	print_list(stack_a);
	// printf("---------------------------------\n");
    return (0);
}