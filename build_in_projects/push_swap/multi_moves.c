/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:58 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/04 15:01:07 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ss, rr, rrr;
void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	update_pos(*a);
	update_pos(*b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	update_pos(*a);
	update_pos(*b);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	update_pos(*a);
	update_pos(*b);
	ft_putstr_fd("rrr\n", 1);
}
