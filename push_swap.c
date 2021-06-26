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

int		main(int argc, char **argv)
{
	t_stack		*stack;
	int			lenght;

	stack = NULL;
	stack = stack_constructor(stack, argc, argv);
	stack_checker(stack);
	lenght = stack_lenght(stack->a);
	if (lenght > 0)
	{
		if (lenght <= 5)
			sort_smallstack(&stack);
		else if (lenght > 5)
			sort_bigstack(&stack);
	}
	stack = stack_destructor(stack);
    return (0);
}
