/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:20:19 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/25 13:26:31 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	num;
	int	a;
	int	b;

	a = atoi(av[1]);
	b = atoi(av[2]);


	num = 0;
	if (ac == 3)
	{
		if (a == 0 && b == 0)
			return (0);
		if (a > b)
			num = b;
		else
			num = a;
		while (num > 0)
		{
			if ((a % num == 0) && (b % num == 0))
			{
				printf("%d\n", num);
				break ;
			}
			num--;
		}
	}
	printf ("\n");
	return (0);
}

