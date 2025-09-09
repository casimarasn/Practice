/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:50:28 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/08 00:38:09 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

static int	get_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		pos;

	tmp = a;
	min = a->num;
	pos = a->pos;
	while (1)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			pos = tmp->pos;
		}
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	return (pos);
}

static int	get_target(t_stack *a, int b_num)
{
	t_stack	*tmp;
	int		best_num;
	int		best_pos;

	best_num = INT_MAX;
	best_pos = get_min_pos(a);
	tmp = a;
	while (1)
	{
		if (tmp->num > b_num && tmp->num < best_num)
		{
			best_num = tmp->num;
			best_pos = tmp->pos;
		}
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	return (best_pos);
}

void	set_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*nb;

	if (!a || !b)
		return ;
	nb = b;
	while (1)
	{
		nb->target_pos = get_target(a, nb->num);
		nb = nb->next;
		if (nb == b)
			break ;
	}
}

t_stack	*cheapest_node(t_stack *b)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;

	if (!b)
		return (NULL);
	tmp = b;
	cheapest = b;
	min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
	while (1)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < min_cost)
		{
			min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
			cheapest = tmp;
		}
		tmp = tmp->next;
		if (tmp == b)
			break ;
	}
	return (cheapest);
}

void	cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = cheapest_node(*b);
	if (node->cost_a == 0 && node->cost_b == 0)
	{
		pa(a, b);
		return ;
	}
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
	move_a(a, node->cost_a);
	move_b(b, node->cost_b);
	pa(a, b);
}
