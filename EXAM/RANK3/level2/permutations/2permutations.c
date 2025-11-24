/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2permutations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:00:38 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/24 19:18:04 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	size;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	sort(char *s, int n)
{
	int	i;
	char tmp;

	i = 0;
	while (n > 0)
	{
		i = 0;
		while (i < n - 1)
		{
			if (s[i] > s[i + 1])
			{
				tmp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = tmp;
			}
			i++;
		}
		n--;
	}
}

void	permu(int pos, char *res, char *av, int *aux)
{

	if (pos == size)
	{
		puts(res);
		return ;
	}
	for (int i = 0; i < size; i++)
	{
		if (aux[i] == 0)
		{
			aux[i] = 1;
			res[pos] = av[i];
			permu(pos + 1, res, av, aux);
			aux[i] = 0;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	size = ft_strlen(av[1]);
	char	*res = calloc(sizeof(char), size + 1);
	int		*aux = calloc(sizeof(int), size);
	sort(av[1], size);
	permu(0, res, av[1], aux);
	free(res);
	free(aux);
	return(0);
}

