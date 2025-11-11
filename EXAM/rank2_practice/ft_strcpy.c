/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:39:08 by msedeno-          #+#    #+#             */
/*   Updated: 2025/08/07 13:32:02 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*char	*ft_strcpy(char *s1, *s2)
{
	int	i = 0;


	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while(s1[i]  && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_strcmp(argv[1], argv[2]);
	printf("%i\n", ft_strcmp(argv[1], argv[2]));
	printf("%i\n", strcmp(argv[1], argv[2]));
}
