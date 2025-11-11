/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:27:55 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 21:09:11 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if ((c == '\n') || (c == '\t') || (c == ' '))
		return (1);
	return (0);
}

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
			while (ft_isspace(str[i]))
				i++;
			while (!ft_isspace(str[i]) && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
			if (str[i] && str[++i])
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
