/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:05:48 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/30 14:37:08 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		start;
	int		end;

	str = av[1];
	if (ac == 2)
	{
		end = ft_strlen(str) - 1;
		while (end >= 0)
		{
			start = end;
			while (start >= 0 && !ft_isspace(str[start]))
				start --;
			i = start + 1;
			while (i <= end)
				write(1, &str[i++], 1);
			if (start > 0)
				write(1, " ", 1);
			end = start - 1;
		}
	}
	write (1, "\n", 1);
	return (0);
}
