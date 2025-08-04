/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:58:23 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/22 11:47:13 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	str = argv[1];
	if (argc == 2)
	{
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
				write (1, "_", 1);
				write (1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		lowercase;
	char	*str;

	i = 0;
	str = argv[1];
	while (str[i] && argc > 1)
	{
		if (ft_is_uppercase(str[i]))
		{
			lowercase = str[i] + 32;
			write(1, "_", 1);
			write(1, &lowercase, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
