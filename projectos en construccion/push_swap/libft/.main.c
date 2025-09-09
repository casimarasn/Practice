/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:22:18 by msedeno-          #+#    #+#             */
/*   Updated: 2025/08/18 15:02:10 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>

int	main(void)
{
//ft_isalpha.c
	printf("%d\n", ft_isalpha ('a'));
	printf("%d\n", ft_isalpha ('A'));
	printf("%d\n", ft_isalpha ('1'));
//ft_isdigit.c
	printf("%d\n", ft_isdigit ('2'));
	printf("%d\n", ft_isdigit ('0'));
	printf("%d\n", ft_isdigit ('v'));	
//ft_isalnum.c
	printf("%d\n", ft_isalnum ('a'));
	printf("%d\n", ft_isalnum ('3'));
	printf("%d\n", ft_isalnum ('a'));
//ft_isascii.c
	printf("%d\n", ft_isascii (48));
	printf("%d\n", ft_isascii(130));
	printf("%d\n", ft_isascii (90));
//ft_isprint.c
	printf("%d\n", ft_isprint (48));
	printf("%d\n", ft_isprint(87));
	printf("%d\n", ft_isprint (126));
//ft_strlen.c
	char	s[]= "hola mundo";
	printf("%zu\n",ft_strlen(s));
	return (0);
//ft_memset.c
	unsigned char	str[20]= "abecedario";
	ft_memset(str, '8', 4);
	printf("%s\n", str);
	return (0);	
//bzero.c
//ft_memcpy.c
	char	src[] = "hola, Mundo";
	char	dest[30];
	printf("%s\n", src);
	printf("%s\n", dest);
	printf("%s\n", (char *) memcpy (dest, src, 20));
	printf("%s\n", (char *) ft_memcpy (dest, src, 20));
	return (0);
//ft_strlcpy.c
	char	str[] = "hola";
	char	dst[10] = "mundo";
	printf("%zu\n", strlcpy(dst, str, 4));
	printf("%zu\n", ft_strlcpy(dst, str, 4));
	return (0);
//ft_substr.c	
	
	char	*str = "Hola mundo";
	char	*result = ft_substr(str, 5, 5);

	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}
	else
		printf("error al imprimir.\n");
}

//ft_split.c

	char const	*s = "hola 767 venga '^& si #( funciona";
	char delim = ' ';
	char	**result = ft_split(s, delim);
	int	i = 0;
	
	while (i < 7)
	{
		printf("%s\n", result[i]);
		i++;
	}


//calloc.c
int	main(void)
{
	char	*str = ft_calloc(5, 1);
	int	i = 0;
	while (i < 4)
	{
		str[i] = 'u';
		i++;
	}
	printf("%s\n", str);
	free(str);
	return (0);
}