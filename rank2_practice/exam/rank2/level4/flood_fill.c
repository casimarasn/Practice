/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:53:57 by msedeno-          #+#    #+#             */
/*   Updated: 2025/08/02 16:48:56 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"

void	fill(char **tab, t_point size, char target, int row, int col, )
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F') || (tab[row][col] != target)
		return ;
	tab[row][col] == 'F';
	fill (tab, size, target, row -1, col);
	fill (tab, size, target, row + 1, col);
	fill (tab, size,target, row, col -1);
	fill (tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target;

	target = tab[begin.y][begin.x];
	fill (tab, size, target, begin.y, begin.x);
}
