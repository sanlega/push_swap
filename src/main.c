/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:09 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/18 23:35:59 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_start(t_stack **lst, t_stack **b)
{
	lstindex(*lst);
	lets_order(*lst, *b);
}

t_stack	*makelist(char **numbers)
{
	int		i;
	t_stack	*newnode;
	t_stack	*stack;
	long long int	carlos;

	stack = NULL;
	i = 0;
	carlos = 0;
	while (numbers[i])
	{
		carlos = ft_atol(numbers[i]);
		if (carlos > INT_MAX || carlos < INT_MIN)
			ft_error();
		newnode = ft_newstack(ft_atol(numbers[i]));
		ft_lstaddback(&stack, newnode);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*lst;
	t_stack *b;

	lst = NULL;
	b = NULL;
	i = 1;
	if (argc < 2 && ft_isnumber(&argv[1][0]))
		exit(0);
	while (i != argc)
	{
		if (!ft_isnumber(argv[i]))
			ft_error();
		i++;
	}
	lst = makelist(argv +1);
	if (check_list(lst))
		ft_start(&lst, &b);
		// lets_order(lst);
	return (0);
}
