/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2first_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:44:31 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/22 11:43:31 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 9 || str[i] == 32)
		i++;
	while ((str[i] != 9) && (str[i] != 32) && (str[i] != '\0'))
	{
		write (1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	main(void)
{
	ft_first_word("		hola mundo");
	ft_first_word("palabra");
	ft_first_word("	primera palabra");
	ft_first_word("		palabra otra");
	ft_first_word("");
	ft_first_word("hello@world again");
	return (0);
}
