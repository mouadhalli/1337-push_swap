/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:30 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/22 15:40:40 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack;
	int			i;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	while (++i < argc)
		add_node(&stack->a, init_node(ft_atoi(argv[i])));
	printf("---------------------------------\n");
	printf("After :\n");
	print_list(stack->a);
	printf("---------------------------------\n");
	return (0);
}