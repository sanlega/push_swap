/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:09 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/17 22:27:01 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack	*makelist(char **numbers)
{
	int		i;
	t_stack	*newnode;
	t_stack	*stack;

	stack = NULL;
	i = 0;
	while (numbers[i])
	{
		newnode = ft_newstack(ft_atoi(numbers[i]));
		ft_lstaddback(&stack, newnode);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*lst;

	i = 1;
	if (argc < 2 && ft_isnumber(&argv[1][0]))
		exit(0);
	while (i != argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	lst = makelist(argv +1);
	if (check_list(lst))
	{
		lstindex(lst);
		ft_printlist(&lst);
	}
		// lets_order(lst);
	return (0);
}
