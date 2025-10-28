/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:10:03 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/03 18:12:55 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	*temp;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	aux = (unsigned char *) dest;
	temp = (unsigned char *) src;
	while (i < n)
	{
		aux[i] = temp[i];
		i++;
	}
	dest = (void *) aux;
	src = (const void *) temp;
	return (dest);
}
