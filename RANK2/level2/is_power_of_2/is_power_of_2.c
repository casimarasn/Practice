/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:03:54 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/22 12:03:13 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	num;

	num = 1;
	while (num <= n)
	{
		if (num == n)
			return (1);
		num *= 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		printf("%d\n", is_power_of_2(atoi(av[1])));
	}
	printf("\n");
	return (0);
}
