/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:35:03 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/19 18:34:04 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_printlist(t_stack **list)
{
	while (*list)
	{
		ft_printf("Num:   %d\n", (*list)->content);
		ft_printf("Index: %d\n\n", (*list)->index);
		(*list) = (*list)->next;
	}
}

void	ft_print_lst_content(t_stack *node)
{
	ft_printf("%d\n", node->content);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*nodo;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		nodo = (*lst)->next;
		free((*lst));
		(*lst) = nodo;
	}
	*lst = NULL;
}
