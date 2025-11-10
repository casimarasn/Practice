/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:21 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/21 11:09:47 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	long int	num;
	int			count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_print_char('-');
		num = -num;
	}
	if (num > 9)
	{
		count += ft_print_nbr(num / 10);
		count += ft_print_char((num % 10) + '0');
	}
	else
		count += ft_print_char(num + '0');
	return (count);
}
