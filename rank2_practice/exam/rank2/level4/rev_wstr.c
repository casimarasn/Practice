/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c        		                            :+:      :+:    :+:   */
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

int	ft_strlen (char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}


int	main(int ac, char **av)
{
	int		len;
	char	*str;
	int		start;
	int		end;
	if (ac != 2)
	{
		write (1, "\n", 1);
		return (1);
	}
	str = av[1];
	len = ft_strlen(str) - 1;
	if (ac == 2)
	{
		while(len >= 0)
		{
			while (len >= 0 && ft_isspace(str[len]))
				len --;
			end = len;
			while(len >= 0 && !ft_isspace(str[len]))
				len --;
			start = len + 1;
			while (start <= end)
			{
				write (1, &str[start], 1);
				start++;
			}
			if (len > 0)
			write (1, " ",1);		
		}
	}
	write (1, "\n", 1);
	return (0);
}
