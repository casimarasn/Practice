/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3n_queens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:44 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/19 13:10:42 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return(n);
}

void	print_array(int *board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < size - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int is_valid (int pos, int value, int *board)
{
	int	i;

	i = 0;
	while ( i < pos)
	{
		if (board[i] == value)
			return (0);
		if (ft_abs(board[i] - value) == ft_abs(i - pos))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int pos, int value, int size, int *board)
{
	if(pos == size)
	{
		print_array(board, size);
		return ;
	}
	while (value < size)
	{
		if (is_valid(pos, value, board))
		{
			board[pos] = value; 
			n_queens(pos + 1, 0, size, board);
		}
		value++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	int board[size];
	n_queens(0, 0, size, board);
	return(0);
}
