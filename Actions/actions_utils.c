
#include "../push_swap.h"

void	free_arr(char **arr)
{
	int		i;
	
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	rotat_call(t_nbr **target, int *pos, char **tag, int middle)
{
	if (*pos <= middle)
	{
		while (*pos > 1)
		{
			rotate_stack(*target, tag[0]);
			(*pos)--;
		}
	}
	else if (*pos > middle)
	{
		while (*pos <= stack_lenght(*target))
		{
			rev_rotate_stack(*target, tag[1]);
			(*pos)++;
		}
		*pos = 1;
	}
}

void	rotat_push(t_nbr **target, t_nbr **dst, int pos, char *tag)
{
	int		middle;
	char	**tagname;

	tagname = ft_split(tag, ' ');
	middle = stack_lenght(*target) / 2;
	if (pos > 1)
		rotat_call(target, &pos, tagname, middle);
	if (pos == 1)
		push_stacktop(target, dst, tagname[2]);
	free_arr(tagname);
}