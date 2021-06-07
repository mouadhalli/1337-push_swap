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
#include "limits.h"

typedef struct s_details
{
    int     		lenght;
    
}               t_details;

typedef	struct	s_nbr
{
	long           nbr;
    t_details 	  *detls;
    struct  s_nbr *next;
}				t_nbr;

//---- PUSH SWAP ACTIONS -----//

void	push_stacktop(t_nbr	**target, t_nbr **dst);
void	rev_rotate_ab(t_nbr *stack_a, t_nbr *stack_b);
void	rev_rotate_stack(t_nbr *head);
void	rotate_ab(t_nbr *stack_a, t_nbr *stack_b);
void	rotate_stack(t_nbr *head);
void	swap_a_b(t_nbr *stack_a, t_nbr *stack_b);
void	swap_firstwo(t_nbr *head);

//---- LINKED LISTS FUNCTIONS -----//

t_nbr    *init_node(long nbr, int lenght);
void    add_node(t_nbr **head, t_nbr *new_node);
t_nbr    *getlast_node(t_nbr *head);
void	print_list(t_nbr *head);
void	remove_node(t_nbr **head, t_nbr *target);
void	new_head(t_nbr **oldhead, t_nbr *newhead);


#endif