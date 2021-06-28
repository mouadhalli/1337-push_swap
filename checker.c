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

int	is_action2(char *buff)
{
	if (buff[0] == 'r' && buff[1] == 'r')
	{
		if (buff[2] == 'r' || buff[2] == 'a' || buff[2] == 'b')
			return (1);
		return (0);
	}
	return (0);
}

int	is_action(char *buff)
{
	if (buff[0] == 's')
	{
		if (buff[1] == 'a' || buff[1] == 'b' || buff[1] == 's')
			return (1);
		return (0);
	}
	else if (buff[0] == 'p')
	{
		if (buff[1] == 'a' || buff[1] == 'b')
			return (1);
		return (0);
	}
	else if (buff[0] == 'r')
	{
		if (buff[1] == 'a' || buff[1] == 'b' || buff[1] == 'r')
			return (1);
		return (0);
	}
	return (0);
}

int	action_checker(char *buff)
{
	int		len;

	len = ft_strlen(buff);
	if ((len == 2 && is_action(buff))
		|| (len == 3 && is_action2(buff)))
		return (1);
	return (0);
}

void	get_input(t_stack *stack)
{
	char	*buff;

	while (get_next_line(0, &buff))
	{
		if (!action_checker(buff))
			exit_error(2, stack, 1);
		if (buff[0] == 's')
			exec_swap(stack, buff);
		else if (buff[0] == 'p')
			exec_push(stack, buff);
		else if (buff[0] == 'r')
			exec_rotate(stack, buff);
		free(buff);
		buff = NULL;
	}
	free(buff);
}

int	main(int argc, char **argv)
{
	t_stack		*stack;

	stack = NULL;
	stack = stack_constructor(stack, argc, argv);
	stack_checker(stack, 1);
	get_input(stack);
	if (stack->b == NULL && is_sorted(stack->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	stack_destructor(stack);
	return (0);
}
