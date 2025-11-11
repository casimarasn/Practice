/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:51:58 by casimarasn        #+#    #+#             */
/*   Updated: 2025/08/06 16:38:16 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	rstr_capitalizer(char *str)
{
	int	len;
	int	end_word;
	int	i;

	len = ft_strlen(str) - 1;
	end_word = 1;
	while (str[len])
	{
		str[len] = ft_tolower(str[len]);
		if (str[len] && (end_word))
			str[len] = ft_toupper(str[len]);
		if (ft_isspace(str[len]))
			end_word = 1;
		else
			end_word = 0;
		len--;
	}
	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			rstr_capitalizer(av[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
