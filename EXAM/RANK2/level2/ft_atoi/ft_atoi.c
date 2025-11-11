/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:32 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:43:20 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	if (c >= 9 && c <= 13 && c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		if ((str[i] == '+') || (str[i] == '-'))
		{
			if (str[i] == '-')
				sign *= -1;
		}
		else if (ft_isdigit(str[i]) == 1)
		{
			num = (num * 10) +(str[i] - '0');
		}
		i++;
	}
	return (sign * num);
}

int	main(void)
{
	char	*str;

	str = "-123456";
	printf("esta es mi funcion:""%d\n", ft_atoi(str));
	printf("esta es la funcion atoi:""%d\n", atoi(str));
	return (0);
}
