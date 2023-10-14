/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:16:08 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/14 17:04:33 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_repeated(t_stack *lst)
{
    t_stack  *current;
    t_stack  *checker;
    int	     duplicates;

    duplicates = 0;
    current = lst;
    while (current && current->next)
    {
        checker = current->next;
        while (checker)
        {
            if (current->content == checker->content)
                duplicates = 1;
            checker = checker->next;
        }
        current = current->next;
    }
    return (duplicates);
}

int is_ordered(t_stack *lst)
{
    if (!lst || !lst->next)
	return (1);
    if (lst->content > lst->next->content)
	return (0);
    return (is_ordered(lst->next));
}

int	check_list(t_stack *lst)
{
    if (is_repeated(lst))
    {
	ft_putstr_fd("ERROR\n", 2);
	exit(EXIT_FAILURE);
    }
    if (is_ordered(lst))
	exit(0);
    return (1);
}
