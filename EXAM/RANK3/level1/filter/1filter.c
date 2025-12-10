/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1filter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:33:43 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/20 17:36:44 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	c;
	int		b_read;
	char	buf[9999];
	int		size;

	i = 0;
	if (ac != 2 || av[1] == NULL)
		return (1);
	size = strlen (av[1]);
	while ((b_read = read(0, &c, 1)) > 0)
	{
		if (b_read < 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if (!ft_strncmp(&buf[i], av[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for ( int j = 0; j < size; j++)
				write( 1, "*", 1);
			i += size;
		}
	}
	return (0);
}
