#include "../push_swap.h"

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
			free(tmp);
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
		free(tmp);
	}
	else
		remove_middlast(tmp, target);
}

void	new_head(t_nbr **oldhead, t_nbr *newhead)
{
	newhead->next = *oldhead;
	(*oldhead) = newhead;
}

void	push_stacktop(t_nbr	**target, t_nbr **dst, char *tag)
{
	if (stack_lenght(*target) > 0)
	{
		if ((*dst) == NULL)
			add_node(dst, init_node((*target)->nbr));
		else	
			new_head(dst, init_node((*target)->nbr));
		remove_node(target, *target);
		ft_putstr_fd(tag, 1);
	}
}