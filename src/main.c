/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:09 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/12 22:07:04 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack *makelist(char **numbers)
{
	int i;
	t_stack *newnode;
	t_stack *stack;

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

int	ft_isnumber(char *argv)
{
	int i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i+1] != '\0')
		i++;
	while (argv[i])
	{
		if(!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int i = 1;
	t_stack *list;

	// ft_printf("Cantidad de Numeros: %d\n\n", argc-1);
	if (argc <= 2)
		exit(0);
	while(i != argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_putstr_fd("ERROR\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	list = makelist(argv +1);
	check_list(list);
	ft_printlist(&list);
	return(0);
}
