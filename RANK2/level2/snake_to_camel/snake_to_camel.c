/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:00:35 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:52:32 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = av[1];
	if (ac == 2)
	{
		while (str[i])
		{
			if (str[i] == '_')
			{
				i++;
				if ((str[i] >= 'a') && (str[i] <= 'z'))
					str[i] -= 32;
			}
			write (1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
