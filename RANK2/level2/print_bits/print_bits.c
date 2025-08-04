/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:54:47 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/23 20:34:58 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	num;

	num = 128;
	while (num >= 1)
	{
		if (octet >= num)
		{
			write (1, "1", 1);
			octet -= num;
		}
		else
			write (1, "0", 1);
		num /= 2;
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 70;
	print_bits(octet);
	return (0);
}
