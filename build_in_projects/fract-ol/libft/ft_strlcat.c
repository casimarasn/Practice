/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:28:45 by msedeno-          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:07 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	is;
	size_t	id;

	is = ft_strlen(src);
	id = ft_strlen(dst);
	if (size <= id)
		return (size + is);
	i = 0;
	while ((src[i] != '\0') && ((id + i) < size - 1))
	{
		{
			dst[id + i] = src[i];
			i++;
		}
	}
	dst[id + i] = '\0';
	return (id + is);
}
