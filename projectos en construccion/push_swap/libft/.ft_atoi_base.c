/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:30:55 by msedeno-          #+#    #+#             */
/*   Updated: 2025/08/18 15:00:52 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
