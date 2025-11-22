/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:52:42 by casimarasn        #+#    #+#             */
/*   Updated: 2025/11/22 19:46:47 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*void	sort(char *str, int n)
{
	int		i;
	char	tmp;

	while (n > 0)
	{
		i = 0;
		while (i < n - 1)
		{
			if (str[i] > str[i + 1])
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
		n--;
	}
}*/

void	sort_in_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;

	i = 0;
	while (i < size - 1)
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
