/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:01 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/05 21:58:55 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	int		size_a;
	int		size_b;

	node_b = b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (!a || !b)
		return ;
	while (1)
	{
		if (node_b->pos <= size_b / 2)
			node_b->cost_b = node_b->pos;
		else
			node_b->cost_b = node_b->pos - size_b;
		if (node_b->target_pos <= size_a / 2)
			node_b->cost_a = node_b->target_pos;
		else
			node_b->cost_a = node_b->target_pos - size_a;
		node_b = node_b->next;
		if (node_b == b)
			break ;
	}
}

void	move_a(t_stack **a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(a, 1);
			cost_a--;
		}
		else
		{
			rra(a, 1);
			cost_a++;
		}
	}
}

void	move_b(t_stack **b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rb(b, 1);
			cost_b--;
		}
		else
		{
			rrb(b, 1);
			cost_b++;
		}
	}
}

void	update_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return ;
	tmp = stack;
	i = 0;
	while (1)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
		if (tmp == stack)
			break ;
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	int	max_num;

	while (*b)
	{
		max_num = find_max(*b);
		while ((*b)->num != max_num)
			rrb(b, 1);
		pa(a, b);
	}
}
