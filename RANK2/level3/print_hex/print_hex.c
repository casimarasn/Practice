/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:46:51 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/26 00:09:42 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int i = 0;
	int	num = 0;
	int	sign = 1;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = (num * 10) + (s[i] - '0');
		else
			break ;
		i++;
	}
	return (sign * num);
}

void	print_hex(int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		print_hex (n / 16);
	write (1, &base[n % 16], 1);
}

int	main(int ac, char **av)
{
	int	num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
