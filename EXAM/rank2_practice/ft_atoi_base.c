/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:41:44 by casimarasn        #+#    #+#             */
/*   Updated: 2025/08/06 17:41:31 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	num;
	int	result;

	i = 0;
	sign = 1;
	while (ft_isspace (str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num = str[i] - '0';
		else if (ft_isalpha(str[i]))
			num = ft_tolower(str[i]) - 'a' + 10;
		else
			break ;
		if (num >= str_base)
			break ;
		result = result * str_base + num;
		i++;
	}
	return (sign * result);
}
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base ("   -1Fz9", 16));
	return (0);
}
