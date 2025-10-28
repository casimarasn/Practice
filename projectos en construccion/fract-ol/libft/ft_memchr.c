/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:17:24 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/02 20:17:21 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ce;
	size_t				i;
	const unsigned char	*ese;

	ce = (unsigned char) c;
	ese = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ese[i] == ce)
			return ((void *)&ese[i]);
		i++;
	}
	return (NULL);
}
