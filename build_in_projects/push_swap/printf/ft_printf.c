/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:51:25 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/12 09:41:41 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start (args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if ((format[i] == '%') && (format[i + 1]))
			count += ft_print_format(args, format[++i]);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// // int main() {
//     int count;

//     printf("--- Pruebas con printf original ---\n");
//     printf("printf: Caracter: %c\n", 'A');
//     printf("printf: String: %s\n", "Hola Mundo");
//     printf("printf: Decimal: %d\n", 12345);/*  */
//     printf("printf: Hexadecimal (minuscula): %x\n", 255);
//     printf("printf: Porcentaje: %%\n");

//     printf("\n--- Pruebas con ft_printf ---\n");
//     count = ft_printf("ft_printf: Caracter: %c\n", 'A');
//     printf("Caracteres impresos: %d\n", count);

//     count = ft_printf("ft_printf: String: %s\n", "Hola Mundo");
//     printf("Caracteres impresos: %d\n", count);

//     count = ft_printf("ft_printf: Decimal: %d\n", 12345);
//     printf("Caracteres impresos: %d\n", count);

//     count = ft_printf("ft_printf: Hexadecimal (minuscula): %x\n", 255);
//     printf("Caracteres impresos: %d\n", count);

//     count = ft_printf("ft_printf: Porcentaje: %%\n");
//     printf("Caracteres impresos: %d\n", count);

//     count = ft_printf("ft_printf: unsigned int: %u\n", 4294967295);
//     printf("Caracteres impresos: %d\n", count);

//     return 0;
// }
