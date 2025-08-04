/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:52:07 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/24 12:08:22 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(char c)
{
	return (c == 32 || c == '\t');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_atoi_base(char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	num = 0;
	int	result = 0;

	while (ft_isspace(str[i]))
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
	return (result * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("   +1Fz9", 16));
}
