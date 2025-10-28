/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:52:53 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/08 00:33:40 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*str_to_int(char **numbers, int count)
{
	int		*arr;
	int		i;
	long	num;

	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		error();
	i = 0;
	while (i < count)
	{
		if (!ft_atoi_strict(numbers[i], &num))
		{
			free(arr);
			error();
		}
		arr[i] = (int)num;
		i++;
	}
	return (arr);
}

int	*copy_and_sort(int *arr, int count)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * count);
	if (!sorted)
		error();
	i = 0;
	while (i < count)
	{
		sorted[i] = arr[i];
		i++;
	}
	sort_int_array(sorted, count);
	return (sorted);
}

void	add_nodes(t_stack **stack_a, int *arr, int *sorted, int count)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < count)
	{
		new = stack_new(arr[i]);
		if (!new)
		{
			free(arr);
			free(sorted);
			error();
		}
		new->pos = find_pos(arr[i], sorted, count);
		stack_add_back(stack_a, new);
		i++;
	}
}

t_stack	*build_stack(char **numbers)
{
	int		count;
	int		*arr;
	int		*sorted;
	t_stack	*stack_a;

	count = 0;
	while (numbers[count])
		count++;
	if (is_duplicated(numbers, count))
		error();
	arr = str_to_int(numbers, count);
	sorted = copy_and_sort(arr, count);
	stack_a = NULL;
	add_nodes(&stack_a, arr, sorted, count);
	free(arr);
	free(sorted);
	return (stack_a);
}
