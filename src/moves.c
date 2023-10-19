/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:00:13 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/19 02:15:56 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **from_lst, t_stack **to_lst)
{
	t_stack	*tmp;
	t_stack	*head_from;
	t_stack *head_to;

	if (!from_lst || !*from_lst)
		return ;
	head_from = *from_lst;
	head_to = NULL;
	if (!*to_lst)
	{
		if (!(*from_lst)->next)
			tmp = NULL;	
		else
			tmp = head_from->next;
		*to_lst = head_from;
		(*to_lst)->next = NULL;
		*from_lst = tmp;
		return ;
	}
	head_to = *to_lst;
	tmp = head_from->next;
	(*from_lst)->next = head_to;
	*to_lst = head_from;
	*from_lst = tmp;
}

void    ft_pb(t_stack **lst, t_stack **b)
{
	ft_push(lst, b);
	ft_printf("pb\n");
}

void    ft_pa(t_stack **lst, t_stack **b)
{
	ft_push(b, lst);
	ft_printf("pa\n");
}

void    ft_ra(t_stack **lst)
{
	t_stack *tmp;
	t_stack	*end_lst;

	tmp = (*lst)->next;
	end_lst = ft_lst_last(*lst);
	end_lst->next = *lst;
	(*lst)->next = NULL;
	*lst = tmp;
	ft_printf("ra\n");
}
