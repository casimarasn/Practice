/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:27:21 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/25 12:36:44 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	num;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		num = a;
	else
		num = b;
	while (1)
	{
		if ((num % a == 0) && (num % b == 0))
			return (num);
		num++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", lcm(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}
