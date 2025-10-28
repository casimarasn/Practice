/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:18:32 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/03 18:12:31 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenlittle;

	lenlittle = ft_strlen (little);
	i = 0;
	if (!little)
		return (NULL);
	if (lenlittle == 0)
		return ((char *)big);
	while ((big[i] != '\0') && (i <= len))
	{
		j = 0;
		while ((little[j] != '\0') && big[i + j] == little[j] && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
