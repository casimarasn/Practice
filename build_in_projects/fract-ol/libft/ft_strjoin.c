/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:58:13 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/07 22:28:40 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	tlen;

	tlen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s = (char *)malloc(tlen * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, tlen);
	ft_strlcat(s, s2, tlen);
	return (s);
}
