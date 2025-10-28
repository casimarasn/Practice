/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:51:40 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/09 21:12:05 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	ch = (char) c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}
