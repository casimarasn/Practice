/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:22:58 by casimarasn        #+#    #+#             */
/*   Updated: 2025/08/26 19:15:03 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack)
		return ;
	tmp = stack->next;
	while (tmp != stack)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(stack);
}

void	free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
