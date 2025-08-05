/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:46:55 by msedeno-          #+#    #+#             */
/*   Updated: 2025/08/05 14:35:59 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_tolower(char c)
{
	if(c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}


char	ft_toupper(char c)
{
	if (c >= 'a' && c <='z')
		c -= 32;
	return (c);
}


int	ft_isspace(char c)
{
	return (c == ' '|| c == '\t');
}


char	*str_capitalizer(char *str)
{
	int	i = 0;
	int	new_word = 1;

	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		if (((new_word) && ft_tolower(str[i])))
			str[i] = ft_toupper(str[i]);
		 if (ft_isspace(str[i]))
			new_word = 1;
		else
			new_word = 0;
		write (1, &str[i], 1);
		i++;
	}
	return(str);
}

int	main(int ac, char **av)
{
	int	i = 1;

	if (ac >= 2)
	{
		while (av[i])
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n",1);
	return(0);
}
