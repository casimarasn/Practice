/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:08:57 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/08 00:34:45 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(int num, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max(t_stack *b)
{
	t_stack	*tmp;
	int		max;
	t_stack	*start;

	if (!b)
		return (0);
	max = b->num;
	start = b;
	tmp = b->next;
	while (tmp != start)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_stack *a)
{
	int		min;
	t_stack	*tmp;

	if (!a)
		return (0);
	min = a->num;
	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*tmp;

	min = a->num;
	pos = 0;
	i = 0;
	tmp = a->next;
	while (tmp != a)
	{
		i++;
		if (tmp->num < min)
		{
			min = tmp->num;
			pos = i;
		}
		tmp = tmp->next;
	}
	return (pos);
}
