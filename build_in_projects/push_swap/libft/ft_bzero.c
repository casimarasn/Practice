/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:13:02 by msedeno-          #+#    #+#             */
/*   Updated: 2025/04/25 14:02:35 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
	s = (void *) a;
}

/*int	main(void)
{
	char	str[] = "abecedario";
	printf("%s\n", str);
	ft_bzero(str, 4);
	int i = 0;
	while (i < 11)
	{
		printf("%c$\n", str[i]);
		i++;
	}
	return (0);
}*/
