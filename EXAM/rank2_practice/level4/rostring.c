/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		end;
	int		start;

	i = 0;
	str = av[1];
	if (ac >= 2)
	{
		while (str[i])
		{
			while (str[i] && ft_isspace(str[i]))
				i++;
			start = i;
			while (str[i] && !ft_isspace(str[i]))
				i++;
			end = i - 1;
			while (str[i] && ft_isspace(str[i]))
				i++;
			while (str[i])
			{
				while (str[i] && ft_isspace(str[i]))
					i++;
				while (str[i] && !ft_isspace(str[i]))
					write (1, &str[i++], 1);
				write (1, " ", 1);
			}
			while (start <= end)
			{
				write(1, &str[start++], 1);
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}
