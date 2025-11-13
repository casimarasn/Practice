/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2filter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:14:06 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/13 12:26:43 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if(s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		r_bytes;
	char	buf[10000];
	char	c;
	int		size;
	
	if (ac != 2 && av[1]== NULL)
		return(1);
	i = 0;
	size = strlen(av[1]);
	while((r_bytes = read(0, &c, 1)) > 0)
	{
		if(r_bytes < 0)
		{
			printf("Error\n");
			return(1);
		}
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if(ft_strncmp(&buf[i], av[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for (int j = 0; j < size; j++)
				write(1, "*", 1);
			i += size;
		}
	}
	return (0);
}

