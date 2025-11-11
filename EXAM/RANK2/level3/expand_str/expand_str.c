/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:20:15 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/22 13:49:01 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || c == '\t')
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
			while (!ft_isspace(str[i]) && (str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			if (str[i] && str[++i])
				write (1, "   ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}
