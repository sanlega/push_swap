/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:33 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/18 23:34:35 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long long int	content;
	int index;
	struct s_stack *next;
} t_stack;

t_stack	*ft_newstack(long long int content);
void	ft_lstaddback(t_stack **lst, t_stack *newer);
t_stack	*ft_lst_last(t_stack *lst);
void	ft_printlist(t_stack **list);
void	ft_print_lst_content(t_stack *node);
int     check_list(t_stack *lst);
void    lets_order(t_stack *lst, t_stack *b);
int		ft_stacksize(t_stack *lst);
void	lstindex(t_stack *lst);
void    ft_ra(t_stack **lst);
void    ft_pa(t_stack **lst, t_stack **b);
void    ft_pb(t_stack **lst, t_stack **b);
int		is_ordered(t_stack *lst);
void	ft_error(void);

#endif
