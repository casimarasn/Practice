/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:52:42 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/30 18:24:31 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_in_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	unsigned int	i;
	int				tab[] = {9, 4, 6, 2};
	unsigned int	size;

	size = 4;
	i = 0;
	sort_in_tab(tab, size);
	while (i < size)
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}
