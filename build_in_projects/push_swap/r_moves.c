/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:32:55 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/08 00:39:24 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra, rb, rra, rrb;

void	ra( t_stack **a, int print)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	*a = (*a)->next;
	update_pos(*a);
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int print)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	*b = (*b)->next;
	update_pos(*b);
	if (print == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rra(t_stack **a, int print)
{
	if (!a || !*a || (*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	update_pos(*a);
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int print)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	*b = (*b)->prev;
	update_pos(*b);
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}
