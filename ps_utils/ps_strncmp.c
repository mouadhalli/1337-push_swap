/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:21:37 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/28 15:21:38 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				result;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)s2;
	d = (unsigned char *)s1;
	i = 0;
	result = 0;
	while (n-- && (s[i] != '\0' || d[i] != '\0'))
	{
		if (d[i] != s[i] && (s[i] != '\0' || d[i] != '\0'))
		{
			result = (d[i] - s[i]);
			return (result);
		}
		i++;
	}
	return (result);
}
