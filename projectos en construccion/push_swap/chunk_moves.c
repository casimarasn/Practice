/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:05:29 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/09 16:19:27 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_count(int size)
{
	if (size <= 10)
		return (1);
	else if (size <= 100)
		return (20);
	else if (size <= 500)
		return (20);
	else
		return (20);
}

void	assign_chunks(t_stack *stack, int size, int chunk_count)
{
	int		chunk_size;
	t_stack	*tmp;

	if (!stack || chunk_count <= 0)
		return ;
	chunk_size = size / chunk_count;
	tmp = stack;
	while (1)
	{
		tmp->chunk = tmp->pos / chunk_size;
		if (tmp->chunk >= chunk_count)
			tmp->chunk = chunk_count - 1;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}

int	has_chunk(t_stack *a, int chunk)
{
	t_stack	*tmp;

	tmp = a;
	if (!a)
		return (0);
	while (1)
	{
		if (tmp->chunk == chunk)
			return (1);
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	return (0);
}

void	final_rotate_a(t_stack **a)
{
	int		size;
	int		i;
	t_stack	*tmp;

	size = stack_size(*a);
	tmp = *a;
	i = 0;
	while (tmp->pos != 0)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= size / 2)
		while ((*a)->pos != 0)
			ra(a, 1);
	else
		while ((*a)->pos != 0)
			rra(a, 1);
}

void	chunk_to_b(t_stack **a, t_stack **b, int chunk)
{
	int	dist_top;
	int	dist_bot;

	while (has_chunk(*a, chunk))
	{
		dist_top = dist_to_chunk(*a, chunk);
		dist_bot = rev_dist_to_chunk(*a, chunk);
		if (dist_top <= dist_bot)
		{
			while (dist_top-- > 0)
				ra(a, 1);
		}
		else
		{
			while (dist_bot-- > 0)
				rra(a, 1);
		}
		pb(a, b);
		rb(b, 1);
	}
}
