/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdecmi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:50:07 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/22 14:05:30 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexdecmi(unsigned long long int n)
{
	int						count;
	int						i;
	char					*str;

	str = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_hexdecmi(n / 16);
	i = n % 16;
	count += ft_print_char(str[i]);
	return (count);
}
