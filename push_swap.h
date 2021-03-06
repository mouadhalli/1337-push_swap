/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:18:17 by mhalli            #+#    #+#             */
/*   Updated: 2021/05/29 15:18:19 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"

typedef struct s_nbr
{
	long			nbr;
	struct s_nbr	*next;
}				t_nbr;

typedef struct s_stack
{
	t_nbr	*a;
	t_nbr	*b;
	int		*arr;
}				t_stack;

t_nbr	*init_node(long nbr);
t_nbr	*getlast_node(t_nbr *head);
void	add_node(t_nbr **head, t_nbr *new_node);
void	remove_node(t_nbr **head, t_nbr *target);
void	new_head(t_nbr **oldhead, t_nbr *newhead);
void	free_list(t_nbr **list);

void	push_stacktop(t_nbr	**target, t_nbr **dst, char *tag);
void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b, int key);
void	rev_rotate_stack(t_nbr *head, char *tag);
void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b, int key);
void	rotate_stack(t_nbr *head, char *tag);
void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b, int key);
void	swap_firstwo(t_nbr *head, char *tag);
void	exec_rotate(t_stack *stack, char *action);
void	exec_push(t_stack *stack, char *action);
void	exec_swap(t_stack *stack, char *action);

int		bigest_nbr(t_nbr *head);
int		get_pos(t_nbr *head, int nbr);
int		stack_lenght(t_nbr *head);
void	rotat_push(t_nbr **head_a, t_nbr **head_b, int index, char *tag);
void	exit_error(int stream, t_stack *stack, int key, int status);
int		chunk_calc(int len, int chunk, int lenght, int m);
int		get_nbrank(int *buff, int nbr, int lenght);
int		*init_buff(t_nbr *content, int lenght);
int		get_index(int lenght, int divisor, int chunk, int sign);

int		is_nbr(char *str);
int		is_int(char *nbr);
int		is_sorted(t_nbr *head);
int		is_duplicated(t_nbr *head);

t_stack	*stack_constructor(t_stack *stack, int argc, char **argv);
t_stack	*stack_destructor(t_stack *stack);
void	stack_checker(t_stack *stack, int is_checker);
void	sort_smallstack(t_stack **stack);
void	sort_bigstack(t_stack **stack);
void	free_arr(char **arr);

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);

#endif