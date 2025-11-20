/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luis2_rip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:26:08 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/19 19:44:51 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	total;

int	min_to_rm(char *s)
{
	int	o;
	int	c;

	o = 0;
	c = 0;
	while (*s)
	{
		if (*s == '(')
			o++;
		else if (*s == ')')
		{
			if (o)
				o--;
			else
				c++;
		}
		s++;
	}
	return (o + c);
}

void	solve(int i, int rm, char *s)
{
	char	t;

	if (!s[i])
	{
		if (rm == total && !min_to_rm(s))
			puts(s);
		return ;
	}
	if (rm > total)
		return ;
	t = s[i];
	solve(i + 1, rm, s);
	s[i] = ' ';
	solve(i + 1, rm + 1, s);
	s[i] = t;
}

int	main(int ac, char **av)
{
	char	*s;

	if (ac != 2)
		return (1);
	s = av[1];
	total = min_to_rm(s);
	if (!total)
	{
		puts("");
		return (1);
	}
	solve(0, 0, s);
	return (0);
}
