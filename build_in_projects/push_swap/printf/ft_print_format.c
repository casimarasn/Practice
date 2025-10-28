/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:15:37 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/22 13:10:59 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (c == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_print_hexdecma(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hexdecmi(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_print_percent();
	return (count);
}
