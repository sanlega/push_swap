/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:30:33 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/17 22:30:29 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

void	lstindex(t_stack *lst)
{
	t_stack	*current;
	t_stack	*mid;
	int		i;
	int		nodes;
	int		mini;

	i = 0;
	nodes = ft_stacksize(lst);
	while (i <= nodes)
	{
		current = lst;
		mini = INT_MAX;
		mid = NULL;
		while (current)
		{
			if (current->index == 0 && \
				(mid == NULL || current->content < mid->content))
				mid = current;
			current = current->next;
		}
		if (mid)
			mid->index = i;
		i++;
	}
}
