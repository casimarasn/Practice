/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:32:50 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/09 15:19:15 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	n1;	
	int	n2;
	int	n3;

	n1 = (*a)->num;
	n2 = (*a)->next->num;
	n3 = (*a)->next->next->num;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a, 1);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a, 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	if (min_pos == 0)
		pb(a, b);
	else if (min_pos == 1)
	{
		ra(a, 1);
		pb(a, b);
	}
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
		pb(a, b);
	}
	else if (min_pos == 3)
	{
		rra(a, 1);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	while (stack_size(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos == 0)
			pb(a, b);
		else if (min_pos <= stack_size(*a) / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	sort_three(a);
	if ((*b)->num < (*b)->next->num)
		sb(b, 1);
	pa(a, b);
	pa(a, b);
}

void	sort_medium(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		push_min_to_b(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size (*a);
	if (size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size <= 10)
		sort_medium(a, b);
}
