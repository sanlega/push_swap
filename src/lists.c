/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:31:53 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/14 17:33:07 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_newstack(int content)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->index = 0;
	newnode->next = NULL;
	return (newnode);
}

void	ft_lstaddback(t_stack **lst, t_stack *newer)
{
	t_stack	*end;

	if (!*lst)
	{
		*lst = newer;
		return ;
	}
	end = ft_lst_last(*lst);
	end->next = newer;
}

t_stack	*ft_lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_printlist(t_stack **list)
{
	while (*list)
	{
		ft_printf("Num: %d\n", (*list)->content);
		(*list)= (*list)->next;
	}
}

void	ft_print_lst_content(t_stack *node)
{
	printf("%d\n", node->content);
}
