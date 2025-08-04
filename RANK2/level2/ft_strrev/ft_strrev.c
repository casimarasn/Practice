/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:44:31 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/23 21:01:29 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	aux;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str)- 1;
	while (i < len)
	{
		aux = str[i];
		str[i] = str[len];
		str[len] = aux;
		i++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char	*s;

	s = "Holaa";
	printf(("%s\n"), ft_strrev(s));
	return (0);
}
