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

void	bubble_sort(int	**buff, int lenght)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (j < lenght - 1)
	{
		while (i < lenght - j -1)
		{
			if ((*buff)[i] > (*buff)[i + 1])
			{
				tmp = (*buff)[i];
				(*buff)[i] = (*buff)[i + 1];
				(*buff)[i + 1] = tmp;
			}
			i++; 
		}
		i = 0;
		j++;
	}
}

int     main(int argc, char **argv)
{
	t_stack		*stack;
    int     i;

	stack = NULL;
	stack = stack_constructor(stack, argc, argv);
	stack_checker(stack);
	if (stack_lenght(stack->a) > 0)
	{
		if (stack_lenght(stack->a) <= 5)
			sort_smallstack(&stack);
		else if (stack_lenght(stack->a) > 5)
			sort_bigstack(&stack);
	}
	stack = stack_destructor(stack);
    return (0);
}
