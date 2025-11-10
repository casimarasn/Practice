/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:11:17 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/07 00:49:56 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*clone;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	clone = (char *)malloc ((slen + 1) * sizeof(char));
	if (!clone)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		clone[i] = (char)s[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}
