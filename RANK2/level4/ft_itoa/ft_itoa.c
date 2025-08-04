/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:01:55 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/29 12:19:22 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int		n = nbr;
	int		count = 0;
	char	*result;

	if (n < 0)
		count ++;
	while (n)
	{
		n = n / 10;
		count ++;
	}
	result = malloc (sizeof (char) * (count + 1));
	result[count] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--count] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (result);
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	printf("\n");
	return (0);
}

