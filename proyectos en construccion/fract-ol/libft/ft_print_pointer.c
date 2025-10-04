/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:17 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/02 20:37:20 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(void *str)
{
	unsigned long long int	n;
	int						count;

	n = (unsigned long long int)str;
	if (!str)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += ft_print_string("0x");
	count += ft_print_hexdecmi(n);
	return (count);
}
