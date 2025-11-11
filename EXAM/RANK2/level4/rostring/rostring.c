/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:44:06 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/30 17:50:46 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char	*str)
{
	int	i;
	int	word;
	int	end;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		word = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		end = i - 1;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, " ", 1);
		while (word <= end)
		{
			write(1, &str[word++], 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
