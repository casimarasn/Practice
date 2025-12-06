/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2permutations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:00:38 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/25 13:27:22 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int n;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return(i);
}

void	sort(char *s, int n)
{
	int	i;
	char tmp;

	while (n > 0)
	{
		i = 0;
		while (i < n - 1)
		{
			if (s[i] > s[i + 1])
			{
				tmp = s[i];
				s[i] = s[i + 1];
				s[i = 1] = tmp;
			}
			i++;
		}
		n--;
	}
}

void	permu(int pos, char *res,char *av, int *aux)

{
	int	i;

	if (pos == n)
	{
		puts(res);
		return ;
	}
	i = 0;
	while (i < n)
	{
		if (aux[i] == 0)
		{
			aux[i] = 1;
			res[pos] = av[i];
			permu(pos + 1, res, av, aux);
			aux[i] = 0;	
		}
		i++;
	}
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	n = ft_strlen(av[1]);
	char *res = calloc(sizeof (char), n + 1);
	int	*aux = calloc(sizeof(int), n);
	sort(av[1], n);
	permu(0, res, av[1], aux);
	free(res);
	free(aux);
	return(0);
}
