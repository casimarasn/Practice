/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:14:40 by casimarasn        #+#    #+#             */
/*   Updated: 2025/08/02 13:50:04 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		len;

	len = ft_strlen(argv[1]);
	if (argc == 2)
	{
		while (len > 0)
		{
			len --;
			write (1, &argv[1][len], 1);
		}
	}
	write (1, "\n", 1);
	return (0);
	if (argc == 2)
	{
		len = 0;
		while (argv[1][len])
			len ++;
		while (len --)
			write (1, &argv[1][len], 1);
	}
	write (1, "\n", 1);
	return (0);
}


char	*rev_print(char *str)
{
	int	i;

	i = 0;

	while (str[i])
		i++;
	i--;
	while (i > 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (str);
}

/*int	main(void)
 {
	 rev_print("rainbow dash");
	 write(1, "\n", 1);
	 rev_print("Ponies are awesome");
	 write(1, "\n", 1); 
	 rev_print("");
	 write(1, "\n", 1);
	 return (0);
}*/
