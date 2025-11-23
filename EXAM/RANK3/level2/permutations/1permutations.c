/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1permutations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:14:41 by casimarasn        #+#    #+#             */
/*   Updated: 2025/11/23 20:23:25 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//puts, malloc, calloc, realloc, free, write
#include <stdio.h>
#include <stdlib.h>

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
	char	tmp;

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

void	permut(int pos, int n, char *av, char *res, int *tmp)
{
	if (pos == n)
	{
		puts(res);
		return ;
	}
	for ( int i = 0; i < n; i++)
	{
		if (!tmp[i])
		{
			tmp[i] = 1;
			res[pos] = av[i];
			permut(pos + 1, n, av, res, tmp);
			tmp[i] = 0;
		}
	}
}
int	main (int ac, char **av)
{
	if (ac < 2)
		return (1);
	int		n = ft_strlen(av[1]);
	char	*res = calloc(sizeof(char), n + 1);
	int		*tmp = calloc(sizeof(int), n);
	//int		tmp[n] = {0};
	sort(av[1], n);
	permut(0, n, av[1], res, tmp);
	free(res);
	free(tmp);
	return (0);
}