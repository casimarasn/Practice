/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:07:44 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/28 23:42:17 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if ((tab[row][col] == 'F') || (tab[row][col] != target))
		return ;
	tab[row][col] = 'F';
	fill (tab, size, target, row - 1, col);
	fill (tab, size, target, row + 1, col);
	fill (tab, size, target, row, col - 1);
	fill (tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	fill (tab, size, target, begin.y, begin.x);
}


char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(void)
{
	char	**area;
	t_point	size;
	t_point	begin;
	char	**zone;

	size = {8, 5};
	begin = {2, 2};
	zone = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1"
	};
	area = make_area(zone, size);
	print_tab(area);
	flood_fill(area, size, begin);
	write(1, "\n", 1);
	print_tab(area);
	return (0);
}

