/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:25:12 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/26 21:17:00 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	str_capitalizer(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		if ((new_word) && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = ft_toupper(str[i]);
		if (ft_isspace(str[i]))
			new_word = 1;
		else
			new_word = 0;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		write (1, "\n", 1);
	while (i < ac)
	{
		str_capitalizer (av[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
