/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:33 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/17 22:26:56 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int content;
	int index;
	struct s_stack *next;
} t_stack;

t_stack	*ft_newstack(int content);
void	ft_lstaddback(t_stack **lst, t_stack *newer);
t_stack	*ft_lst_last(t_stack *lst);
void	ft_printlist(t_stack **list);
void	ft_print_lst_content(t_stack *node);
int     check_list(t_stack *lst);
void    lets_order(t_stack *lst);
int	ft_stacksize(t_stack *lst);
void	lstindex(t_stack *lst);

#endif
