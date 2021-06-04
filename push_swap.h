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
    t_details 	  detls;
    struct  s_nbr *next;
}				t_nbr;



#endif