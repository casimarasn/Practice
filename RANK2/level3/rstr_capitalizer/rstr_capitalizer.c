/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:13:17 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/26 19:17:27 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		if (((str[i] >= 'a' && str[i] <= 'z') && (ft_isspace(str[i + 1])))
			|| str[i + 1] == '\0')
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		write (1, "\n", 1);
	else
	{
		while (i < ac)
		{
			rstr_capitalizer (av[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}
