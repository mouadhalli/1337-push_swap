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

t_nbr    *init_node(int nbr)
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

void	print_list(t_nbr *head)
{
	while (head->next != NULL)
	{
		printf("nbr == %ld\n", head->nbr);
		head = head->next;
	}
	printf("nbr == %ld\n", head->nbr);

}

void	exit_error(int stream)
{
	ft_putstr_fd("error:\n", stream);
	exit(-1);
}

//----------------------ACTIONS--------------------//

void	swap_firstwo(t_nbr *head)
{
	if (head->detls.lenght > 1)
	{
		head->nbr = head->nbr + head->next->nbr;				// a = a + b // 5 = 5 + 4 => 9
		head->next->nbr = head->nbr - head->next->nbr;			// b = a - b => (a + b) - b // 4 = 9 - 4 => 5
		head->nbr = head->nbr - head->next->nbr;				// 5 + 4 = 9 || 9 - 4 = 5 || 9 - 5 = 4
	}
}

void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b)
{
	swap_firstwo(stack_a);
	swap_firstwo(stack_b);
}

void	rotate_stack(t_nbr *head)
{
	int		tmp;

	tmp = head->nbr;
	while(head->next != NULL)
	{
		head->nbr = head->next->nbr;
		head->next->nbr = tmp;
		head = head->next;
	}
}

void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rev_rotate_stack(t_nbr *head)
{
	int		tmp;
	int		tmp2;
	t_nbr	*tail;

	tail = getlast_node(head);
	tmp2 = 0;
	tmp = head->next->nbr;
	head->next->nbr = head->nbr;
	head->nbr = tail->nbr;
	head = head->next;
	while (head->next != NULL)
	{
		tmp2 = head->next->nbr;
		head->next->nbr = tmp;
		tmp = tmp2;
		head = head->next;
	}
}

void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
}

void	push_stacktop(t_nbr	*target, t_nbr *dst)
{

	if (target->nbr < INT_MAX)
	{
		dst->nbr = target->nbr;
		target->nbr = INT_MAX;
	}
}


//--------------------------------------------------//

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
	printf("Befor\n");
	print_list(stack_a);
	// rotate_stack(stack_a);
	// push_stacktop(stack_b, stack_a);
	rev_rotate_stack(stack_a);
	// swap_firstwo(stack_a);
	printf("---------------------------------\n");
	printf("After\n");
	print_list(stack_a);
	printf("---------------------------------\n");
    return (0);
}