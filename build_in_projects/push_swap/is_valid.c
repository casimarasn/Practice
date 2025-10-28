/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:37:58 by casimarasn        #+#    #+#             */
/*   Updated: 2025/09/07 22:55:04 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty_str(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i][0] == '\0')
			error();
		i++;
	}
}

int	is_valid_char(char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (ft_isdigit(s[j]) || s[j] == ' ')
			j++;
		else if (s[j] == '+' || s[j] == '-')
		{
			if (((j > 0) && s[j - 1] != ' ') || (!ft_isdigit(s[j + 1])))
				error();
			j++;
		}
		else
			error();
	}
	return (1);
}

void	is_valid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == '\0')
			error();
		is_valid_char(av[i]);
		i++;
	}
}

int	is_duplicated(char **numbers, int count)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 0;
	while (i < count)
	{
		ft_atoi_strict(numbers[i], &num1);
		j = i + 1;
		while (j < count)
		{
			ft_atoi_strict(numbers[j], &num2);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (1)
	{
		if (tmp->next == a)
			break ;
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
