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

#include "libft/libft.h"

typedef	struct	s_nbr
{
	long           nbr;
    struct  s_nbr *next;
}				t_nbr;

//---- LINKED LISTS FUNCTIONS -----//

t_nbr    *init_node(long nbr);
void    add_node(t_nbr **head, t_nbr *new_node);
t_nbr    *getlast_node(t_nbr *head);
void	print_list(t_nbr *head);
void	remove_node(t_nbr **head, t_nbr *target);
void	new_head(t_nbr **oldhead, t_nbr *newhead);

//---- PUSH SWAP ACTIONS -----//

void	push_stacktop(t_nbr	**target, t_nbr **dst, char *tag);
void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b);
void	rev_rotate_stack(t_nbr *head, char *tag);
void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b);
void	rotate_stack(t_nbr *head, char *tag);
void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b);
void	swap_firstwo(t_nbr *head, char *tag);


//---- PUSH SWAP UTILS -----//

int		bigest_nbr(t_nbr *head);
int		small_nbr(t_nbr *head);
int		get_pos(t_nbr *head, int nbr);
int		stack_lenght(t_nbr *head);
void	rotat_push(t_nbr **head_a, t_nbr **head_b, int index, char *tag);
int		inc(int range, int st_lenght, int divisor);
int		decrement(int range, int lenght);
void	fill_buff(t_nbr *head, int **buff);
void	exit_error(int stream);
int		chunk_calc(int len, int chunk, int lenght, int m);

//---- SORTING FUNCTIONS -----//



#endif