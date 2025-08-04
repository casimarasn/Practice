/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:22:48 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:53:43 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	tabla[256] = {0};

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !tabla[(int)argv[2][j]])
				{
					tabla[(int)argv[2][j]] = 1;
					write(1, &argv[1][i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
