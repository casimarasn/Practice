/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int	ft_isspace(char c)
{
	return (c == ' ' || c =='\t');
}
int	ft_atoi(char *str)
{
	int	i;
	int num;
	int	sign;

	i = 0;
	sign = 1;
	while  (str[i])
	{
		if (ft_isspace (str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			num = (num  * 10) + str[i] - '0';
		}
		i++;
	}
	return (sign * num);
}


int	main (int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d",ft_atoi(av[1]));
	}
	printf ("\n");
	return (0);
}
