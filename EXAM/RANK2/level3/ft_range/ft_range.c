/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:54:47 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/24 15:24:11 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	if (start > end)
		len = (start - end) + 1;
	else
		len = (end - start) + 1;
	tab = malloc(len * (sizeof (int)));
	while (i < len)
	{
		tab[i] = start;
		if (start > end)
			start --;
		else if (end > start)
			start++;
		i++;
	}
	return (tab);
}

int	main(void)
{
	int	i;
	int	*array;

	i = 0;
	array = ft_range (0, 0);
	while (i < 1)
	{
		printf("%i\n", array[i]);
		i++;
	}
	free (array);
}

