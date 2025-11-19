/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4n_queens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:21:34 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/19 22:16:49 by msedeno-         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i != size - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	isvalid(int pos, int value, int *board)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (board[i] == value)
			return (0);
		if (ft_abs(board[i] - value) == ft_abs(i - pos))
			return (0);
		i++;
	}
	return (1);
}

void	nqueens(int pos, int size, int *board)
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
		if (isvalid(pos, value, board))
		{
			board[pos] = value;
			nqueens(pos + 1, size, board);
		}
		value++;
	}
}

int	main(int ac, char **av)
{
	int	size;

	if (ac != 2)
		return (1);
	size = atoi(av[1]);
	int	board[size];
	nqueens(0, size, board);
	return (0);
}
