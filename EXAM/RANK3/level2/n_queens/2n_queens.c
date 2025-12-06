/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2n_queens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:17:20 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/25 11:07:59 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	print_array(int *board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d", board[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	is_valid(int pos, int value, int *board)
{
	int 	i;

	i = 0;
	while (i < pos)
	{
		if (value == board[i])
			return (0);
		if (ft_abs(value - board[i]) == ft_abs(pos - i))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int pos, int size, int *board)
{
	int	value;

	value = 0;
	if (pos == size)
	{
		print_array(board, size);
		return ;
	}
	while (value < size)
	{
		if (is_valid(pos, value, board))
		{
			board[pos] = value;
			n_queens(pos + 1, size, board);
		}
		value++;
	}
}

int	main(int ac, char **av)
{
	int	size;

	if (ac != 2)
		return(1);
	size = atoi(av[1]);
	int	board[size];
	n_queens(0, size, board);
	return (0);
}
