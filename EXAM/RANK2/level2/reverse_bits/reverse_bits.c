/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:32:47 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/23 20:36:11 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;

	res = 0;
	if (octet >= 128)
	{
		octet -= 128;
		res += 1;
	}
	if (octet >= 64)
	{
		octet -= 64;
		res += 2;
	}
	if (octet >= 32)
	{
		octet -= 32;
		res += 4;
	}
	if (octet >= 16)
	{
		octet -= 16;
		res += 8;
	}
	if (octet >= 8)
	{
		octet -= 8;
		res += 16;
	}
	if (octet >= 4)
	{
		octet -= 4;
		res += 32;
	}
	if (octet >= 2)
	{
		octet -= 2;
		res += 64;
	}
	if (octet >= 1)
	{
		octet -= 1;
		res += 128;
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%d\n", reverse_bits (atoi(av[1])));
	}
	return (0);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	res = 0;
	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return (res);
}
