/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1filter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:52:07 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/11 12:29:00 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		b_read;
	char	buf[10000];
	char	c;
	int		size;

	if (ac != 2 && av[1] == NULL)
		return(1);
	i = 0;
	while ((b_read = read(0, &c, 1)) > 0)
	{
		if (b_read < 0)
			return (1);
		buf[i] = c;
		i++;
	}
	size = strlen(av[1]);
	buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if (ft_strncmp(&buf[i], av[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for ( int j = 0; j < size; j++)
					write(1, "*", 1);
			i += size;
		}
	}
	return (0);
}
