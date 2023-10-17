/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:35:34 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/17 20:22:26 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static unsigned long	next_hash(unsigned long current_hash)
{
	return (current_hash * 6269667103370058243UL + 1);
}

unsigned long	harder_hash(unsigned long hash)
{
	void	*ptr;
	char	*str;
	char	*ptr_str;
	int		c;

	ptr = malloc(1);
	str = malloc(256);
	if (!ptr || !str)
		exit (1);
	ptr_to_hex(ptr, str);
	ptr_str = str;
	c = *ptr_str;
	while (c)
	{
		ptr_str++;
		hash = ((hash << 5) + hash) + c;
		c = *ptr_str;
	}
	return (free(ptr), free(str), hash);
}

unsigned long	simple_hash(void)
{
	unsigned long	hash;
	void			*ptr;
	char			*str;
	char			*ptr_str;
	int				c;

	hash = 3674298;
	ptr = malloc(1);
	str = malloc(256);
	if (!ptr || !str)
		exit (1);
	ptr_to_hex(ptr, str);
	ptr_str = str;
	c = *ptr_str;
	while (c)
	{
		ptr_str++;
		hash = ((hash << 5) + hash) + c;
		c = *ptr_str;
	}
	return (free(ptr), free(str), harder_hash(hash));
}

void	generate_numbers(unsigned long hash, int *output, int n, int *minmax)
{
	int				range;
	int				i;
	unsigned long	new_hash;
	int				min;
	int				max;

	min = minmax[0];
	max = minmax[1];
	range = max - min + 1;
	i = 0;
	new_hash = hash;
	while (i < n)
	{
		output[i] = (new_hash % range) + min;
		new_hash = next_hash(new_hash);
		i++;
	}
}

int	*ft_rand_numers(int min, int max, int quantity)
{
	unsigned long	hash_val;
	int				*numbers;
	int				minmax[2];

	hash_val = simple_hash();
	numbers = malloc(quantity * sizeof(int));
	minmax[0] = min;
	minmax[1] = max;
	if (!numbers)
		exit(1);
	generate_numbers(hash_val, numbers, quantity, minmax);
	return (numbers);
}
