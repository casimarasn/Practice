/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:46:37 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/09 15:39:36 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_stack **a, int min_pos, int size)
{
	if (min_pos <= size / 2)
	{
		while ((*a)->pos != 0)
			ra(a, 1);
	}
	else
	{
		while ((*a)->pos != 0)
			rra(a, 1);
	}
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_pos(*a);
	size = stack_size(*a);
	if (min_pos == 0)
		pb(a, b);
	else if (min_pos == 1)
	{
		ra(a, 1);
		pb(a, b);
	}
	else if (min_pos == size - 1)
	{
		rra(a, 1);
		pb(a, b);
	}
	else
	{
		rotate_to_min(a, min_pos, size);
		pb(a, b);
	}
}

void	handle_small_numbers(t_stack **a, t_stack **b, int num_chunks)
{
	int	chunk;

	chunk = 0;
	while (chunk < num_chunks)
	{
		chunk_to_b(a, b, chunk);
		chunk++;
	}
}

void	handle_large_numbers(t_stack **a, t_stack **b)
{
	int	num_chunks;
	int	chunk;

	num_chunks = chunk_count(stack_size(*a));
	chunk = 0;

	while (chunk < num_chunks)
	{
		chunk_to_b(a, b, chunk);
		chunk++;
	}
	/*while (*b)
	{
		set_target_pos(*a, *b);
		calculate_costs(*a, *b);
		cheapest_to_a(a, b);
	}*/
}

void	return_elements_to_a(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 0)
		push_back(a, b);
	else
	{
		while (*b)
		{
			// if ((*b)->num < find_min(*a))
			// {
			// 	pa(a, b);
			// 	continue ;
			// }
			// if ((*b)->num > find_max(*a))
			// {
			// 	pa(a, b);
			// 	continue ;
			// }
			update_pos(*a);
			update_pos(*b);
			set_target_pos(*a, *b);
			calculate_costs(*a, *b);
			cheapest_to_a(a, b);
		}
	}
	final_rotate_a(a);
}
