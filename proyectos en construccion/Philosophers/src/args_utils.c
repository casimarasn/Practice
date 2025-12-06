/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:53:27 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/28 18:45:30 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v');
}

int	ft_isdigit(int n)
{
	return ((n >= '0') && (n <= '9'));
}

int	ft_atoi_strict(const char *str)
{
	long	result;

	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		return (-1);
	if (!ft_isdigit(*str))
		return (-1);
	result = 0;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if ((result > INT_MAX))
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	return ((int)result);
}

int	ft_strstr(char *s, char *finder)
{
	int	i;
	int	j;

	i = 0;
	if (!finder[0])
		return (1);
	while (s[i])
	{
		j = 0;
		while (s[i + j] && finder[j] && s[i + j] == finder[j])
			j++;
		if (!finder[j])
			return (1);
		i++;
	}
	return (0);
}

char	*get_color(char *status)
{
	if (strstr(status, "is eating"))
		return (GREEN);
	else if (strstr(status, "is sleeping"))
		return (BLUE);
	else if (strstr(status, "is thinking"))
		return (YELLOW);
	else if (strstr(status, "has taken a fork"))
		return (ORANGE);
	else if (strstr(status, "died"))
		return (RED);
	return (RESET);
}
