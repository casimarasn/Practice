/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:57:00 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/26 22:44:33 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	n;

	sign = 1;
	n = 0;
	while (*str < 33)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (sign * n);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	num;

	i = 0;
	num = ft_atoi(av[1]);
	if (ac == 2)
	{
		while (i <= 9)
		{
			ft_putnbr(num);
			write(1, " x ", 3);
			ft_putnbr(i);
			write (1, " = ", 3);
			ft_putnbr(num * i);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
