/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1n_queen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 05:40:34 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/18 07:08:46 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

int	ft_isvalid (int pos, int value, int *board)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (value == board[i])
			return(0);
		if(ft_abs(board[i] - value) == ft_abs(i - pos))
			return (0);
		i++;
	}
	return(1);
	
}
void	n_queens(int pos, int size, int *board)
{
	int	value = 0;
	if (pos == size)
	{
		print_array(board, size);
//		for (int i = 0; i < pos; i++)
//			fprintf(stdout, "%d", board[i]);
		return ;
	}
	while (value < size)
	{
		if (ft_isvalid(pos, value, board))
		{
			board[pos] = value;
			n_queens(pos + 1, size, board);
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
	n_queens(0,size, board);
	return (0);
}
