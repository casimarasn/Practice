/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:37:06 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 20:46:39 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen (src);
	cpy = (char *) malloc(len + 1 * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy [i] = '\0';
	return (cpy);
}

int	main(void)
{
	char	*s;

	s = "holii";
	printf("%s", ft_strdup(s));
	return (0);
}
