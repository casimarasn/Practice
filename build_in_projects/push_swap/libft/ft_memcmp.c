/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:20:22 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/02 21:16:49 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ese1;
	unsigned char	*ese2;
	size_t			i;

	ese1 = (unsigned char *) s1;
	ese2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ese1[i] != ese2[i])
			return (ese1[i] - ese2[i]);
		i++;
	}
	return (0);
}
