/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:25:29 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/24 15:46:21 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*tab;
	int	len;

	i = 0;
	if (end > start)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;
	tab = (int *)malloc(len * (sizeof (int)));
	while (i < len)
	{
		tab[i] = end;
		if (end > start)
			end--;
		else if (end < start)
			end++;
		i++;
	}
	return (tab);
}

int	main(void)
{
	int	i;
	int	*array;

	i = 0;
	array = (ft_rrange(-1, 2));
	while (i < 4)
	{
		printf("%i\n", array[i]);
		i++;
	}
	free (array);
}
