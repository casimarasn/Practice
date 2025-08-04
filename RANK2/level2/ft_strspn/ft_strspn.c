/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:54:23 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/23 20:54:26 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(char *str1, char *str2)
{
	int		i;
	int		j;
	size_t	res;

	i = 0;
	while (str1[i])
	{
		j = 0;
		res = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
				res = 1;
			j++;
		}
		if (res == 0)
			return (i);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%lu\n", ft_strspn(argv[1], argv[2]));
		printf("%lu", strspn(argv[1], argv[2]));
	}
	printf("\n");
}
