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

// void	print_list(t_nbr *head)
// {
// 	while (head->next != NULL)
// 	{
// 		printf("nbr == %ld\n", head->nbr);
// 		head = head->next;
// 	}
// 	printf("nbr == %ld\n", head->nbr);

// }

// t_stack		*get_input(t_stack *stack, int input_len, char **argv)
// {
// 	int		i;
// 	int		j;
// 	char	**input;

// 	i = 0;
// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	stack->a = NULL;
// 	stack->b = NULL;
// 	stack->arr = NULL;
// 	while (++i < input_len)
// 	{
// 		j = 0;
// 		input = ft_split(argv[i], ' ');
// 		while (input[j])
// 		{
// 			if (!is_nbr(input[j]) || !is_int(input[j]))
// 				exit_error(2, stack, 1);
// 			add_node(&stack->a, init_node(ft_atoi(input[j++])));
// 		}
// 	}
// 	free_arr(input);
// 	return (stack);
// }

int	main(int argc, char **argv)
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
