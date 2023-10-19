/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:14:57 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/19 07:01:48 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	ft_printf("sa\n");
}

void	ft_rra(t_stack **lst)
{
	t_stack	*first_node;
	t_stack	*penul_node;
	t_stack	*last_node;

	first_node = *lst;
	penul_node = *lst;
	while (penul_node && penul_node->next && penul_node->next->next)
		penul_node = penul_node->next;
	last_node = penul_node->next;
	penul_node->next = NULL;
	last_node->next = first_node;
	*lst = last_node;
	ft_printf("rra\n");
}
