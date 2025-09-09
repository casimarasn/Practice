/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:48 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/09 12:51:33 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	t_stack	*tmp;
	int		count;

	ft_printf("Stack %c:\n", name);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return ;
	}
	tmp = stack;
	count = 0;
	while (1)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
		if (++count > 100)
		{
			ft_printf("Bucle infinito detectado\n");
			break ;
		}
	}
}

void	push_swap(t_stack **a, t_stack **b, int num_chunks)
{
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
	{
		sort_small(a, b);
		return ;
	}
	*b = NULL;
	assign_chunks(*a, stack_size(*a), num_chunks);
	if (num_chunks == 10)
		handle_large_numbers(a, b);
	else
		handle_small_numbers(a, b, num_chunks);
	return_elements_to_a(a, b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**numbers;
	int			num_chunks;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	numbers = join_arguments(ac, av);
	if (!numbers || !numbers[0] || !*numbers[0])
	{
		free_array(numbers);
		error();
	}
	stack_a = build_stack(numbers);
	num_chunks = chunk_count(stack_size(stack_a));
	push_swap(&stack_a, &stack_b, num_chunks);
	free_stack(stack_a);
	free_array(numbers);
	return (0);
}
