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

	stack = NULL;
	stack = stack_constructor(stack, argc, argv);
	stack_checker(stack);
	printf("---------------------------------\n");
	printf("After :\n");
	print_list(stack->a);
	printf("---------------------------------\n");
	return (0);
}