/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:34:34 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/23 21:01:59 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, int len)
{
	int	i;
	int	result;

	i = 0;
	if (len == 0)
		return (0);
	result = tab[0];
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}

int	main(void)
{
	int	tab[] = {-1, -3, -2, -5, -9};

	printf("%d\n", max(tab, 5));
	return (0);
}
