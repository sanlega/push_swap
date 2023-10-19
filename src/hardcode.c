/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:19:02 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/19 07:03:13 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_smallest(t_stack *lst)
{
	int	min_val;

	min_val = INT_MAX;
	while (lst)
	{
		if (lst->index < min_val)
			min_val = lst->index;
		lst = lst->next;
	}
	return (min_val);
}

void	sort2(t_stack **lst)
{
	ft_sa(lst);
}

void	sort3(t_stack **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)->index;
	second = (*lst)->next->index;
	third = (*lst)->next->next->index;
	if (first > second && second < third && first < third)
		ft_sa(lst);
	else if (first > second && first > third && second > third)
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if (first > second && first > third && second < third)
		ft_ra(lst);
	else if (first < second && first < third && second > third)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
	else if (first < second && first > third && second > third)
		ft_rra(lst);
}

void	sort4(t_stack **lst, t_stack **b)
{
	int	min;

	min = get_smallest(*lst);
	while ((*lst)->index != min)
		ft_ra(lst);
	ft_pb(lst, b);
	sort3(lst);
	ft_pa(lst, b);
}

void	sort5(t_stack **lst, t_stack **b)
{
	int	min;
	int	bool;

	min = get_smallest(*lst);
	bool = 0;
	if (ft_lst_last(*lst)->index == min)
	{
		ft_rra(lst);
		bool = 1;
	}
	else
	{
		while ((*lst)->index != min)
			ft_ra(lst);
	}
	ft_pb(lst, b);
	sort4(lst, b);
	ft_pa(lst, b);
}
