/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:09 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/19 19:25:11 by slegaris         ###   ########.fr       */
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
	if (ft_stacksize(*lst) == 2)
		sort2(lst);
	if (ft_stacksize(*lst) == 3)
		sort3(lst);
	if (ft_stacksize(*lst) == 4)
		sort4(lst, b);
	if (ft_stacksize(*lst) == 5)
		sort5(lst, b);
	else
		lets_order(lst, b);
}

t_stack	*makelist(char **numbers)
{
	int				i;
	t_stack			*newnode;
	t_stack			*stack;
	long long int	atolcheck;

	stack = NULL;
	i = 0;
	atolcheck = 0;
	while (numbers[i])
	{
		atolcheck = ft_atol(numbers[i]);
		if (numbers[i][0] == '\0' || atolcheck > INT_MAX
			|| atolcheck < INT_MIN)
			ft_error(&stack);
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
	t_stack	*b;

	lst = NULL;
	b = NULL;
	i = 1;
	if (argc < 2 && ft_isnumber(&argv[1][0]))
		exit(0);
	while (i != argc)
	{
		if (!ft_isnumber(argv[i]))
			ft_error(&lst);
		i++;
	}
	lst = makelist(argv +1);
	if (!*argv[1])
		ft_error(&lst);
	if (check_list(lst))
		ft_start(&lst, &b);
	ft_stackclear(&lst);
	ft_stackclear(&b);
	return (0);
}
