/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:48 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/26 10:37:20 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *s)
{
	int	i;
	int	j;

	if (!s)
		write (1, "\n", 1);
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] >= 65 && s[i] <= 90)
		{
			while (j++ < s[i] - 'A' + 1)
				write(1, &s[i], 1);
		}
		else if (s[i] >= 97 && s[i] <= 122)
		{
			while (j++ < s[i] - 'a' + 1)
				write (1, &s[i], 1);
		}
		else
			write (1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write (1, "\n", 1);
	return (0);
}
