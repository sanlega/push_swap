/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:54:39 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/18 23:45:00 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void    lets_order(t_stack *lst, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!is_ordered(lst))
	{
		j = ft_stacksize(lst);
		while (j > 0)
		{
			if ((lst->index >> i & 1) == 1)
				ft_ra(&lst);
			else
				ft_pb(&lst, &b);
			j--;
		}
		while (ft_stacksize(b) != 0)
			ft_pa(&lst, &b);
		i++;
	}
	// ft_printlist(&lst);
}
