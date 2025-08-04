/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:39:15 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:49:42 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	ascii[255] = {0};

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (ascii[(int)av[1][i]] == 0)
			{
				ascii[(int)av[1][i]] = 1;
				write (1, &av[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (ascii[(int)av[2][i]] == 0)
			{
				ascii[(int) av[2][i]] = 1;
				write (1, &av[2][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
