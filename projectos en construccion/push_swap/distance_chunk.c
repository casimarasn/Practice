/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:50:59 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/09 16:07:50 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_to_min_chunk(t_stack *a, int chunk)
{
	int		dist;
	int		min;
	int		min_dist;
	t_stack	*tmp;

	tmp = a;
	dist = 0;
	min = INT_MAX;
	min_dist = 0;
	while (1)
	{
		if (tmp->chunk == chunk && tmp->num < min)
		{
			min = tmp->num;
			min_dist = dist;
		}
		tmp = tmp->next;
		dist++;
		if (tmp == a)
			break ;
	}
	return (min_dist);
}

int	rev_dist_to_min_chunk(t_stack *a, int chunk)
{
	int		dist;
	int		min;
	int		min_dist;
	t_stack	*tmp;

	tmp = a;
	dist = 0;
	min = INT_MAX;
	min_dist = 0;
	while (1)
	{
		if (tmp->chunk == chunk && tmp->num < min)
		{
			min = tmp->num;
			min_dist = dist;
		}
		tmp = tmp->prev;
		dist++;
		if (tmp == a)
			break ;
	}
	return (min_dist);
}

int	dist_to_chunk(t_stack *a, int chunk)
{
	int		dist;
	t_stack	*tmp;

	tmp = a;
	dist = 0;
	if (!a)
		return (0);
	while (1)
	{
		if (tmp->chunk == chunk)
			return (dist);
		tmp = tmp->next;
		dist++;
		if (tmp == a)
			break ;
	}
	return (dist);
}

int	rev_dist_to_chunk(t_stack *a, int chunk)
{
	int		dist;
	t_stack	*tmp;

	tmp = a;
	dist = 0;
	if (!a)
		return (0);
	while (1)
	{
		if (tmp->chunk == chunk)
			return (dist);
		tmp = tmp->prev;
		dist++;
		if (tmp == a)
			break ;
	}
	return (dist);
}

int	median_b(t_stack *b)
{
	int		size;
	int		*arr;
	int		i;
	t_stack	*tmp;
	int		median;

	size = stack_size(b);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	tmp = b;
	i = 0;
	while (i < size)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	sort_int_array(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
