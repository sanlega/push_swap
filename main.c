/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:09 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/12 19:59:31 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_isnumber(char *argv)
{
	int i;

	i = 0;
	if (argv[i] == '-')
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

	ft_printf("Cantidad de Numeros: %d\n\n", argc-1);
	while(i != argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_putstr_fd("error\n", 2);
			exit(EXIT_FAILURE);
		}
		// ESTO ES PARA PROBAR:
		else
			ft_printf("Argv %d: %d\n", i,ft_atoi(argv[i]));
		i++;
	}
	makelist(argv +1);
	return(0);
}
