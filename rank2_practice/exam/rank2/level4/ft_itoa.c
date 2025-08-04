/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char	*result;
	int		count;
	int		n;

	count = 0;
	n = nbr;
	if (n <= 0)
		count ++;
	while (n)
	{
		n /= 10;
		count ++;
	}
	result = malloc ((count + 1) * sizeof (char));
	result[count] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		count--;
		result[count] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);	
}

int	main (int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s",ft_itoa(atoi(av[1])));
	}
	printf("\n");
	return (0);
}
