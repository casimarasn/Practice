/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:19:38 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 21:10:36 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] <= 32)
		i++;
	if ((s[i] == '+') || (s[i] == '-'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ft_putnbr( int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write (1, &c, 1);
}

int	ft_isprime(int n)
{
	int	i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int	add_prime_sum(int nbr)
{
	int	n;
	int	count;

	n = 2;
	count = 0;
	while (n <= nbr)
	{
		if (ft_isprime(n) == 0)
			count += n;
		n++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
		nbr = ft_atoi (argv[1]);
		ft_putnbr(add_prime_sum(nbr));
	}
	else
		write (1, "0", 2);
	write (1, "\n", 2);
	return (0);
}
