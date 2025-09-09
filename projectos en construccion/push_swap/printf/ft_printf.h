/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:54:50 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/22 14:05:44 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_print_format(va_list args, char c);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_percent(void);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexdecma(unsigned long long n);
int	ft_print_hexdecmi(unsigned long long int n);
int	ft_print_pointer(void *str);

#endif
