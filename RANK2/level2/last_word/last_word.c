/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:00:14 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:50:06 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	return ((c == '\t') || (c == ' '));
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	str = argv[1];
	i = ft_strlen(str) - 1;
	if (argc == 2)
	{
		while (ft_isspace(str[i]))
			i--;
		while (!ft_isspace(str[i]) && (i >= 0))
			i--;
		i++;
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
