/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:18:05 by casimarasn        #+#    #+#             */
/*   Updated: 2025/07/08 23:26:47 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**word;
	char	*start;

	i = 0;
	word = malloc (100 * sizeof (char *));
	if (!word)
		return (NULL);
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		if (!str)
			break ;
		start = str;
		while (*str && !(*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		word[i] = malloc (str - start + 1);
		if (!word[i])
			return (NULL);
		j = 0;
		while (start < str)
			word[i][j++] = *start++;
		word[i][j] = '\0';
		i++;
	}
	word[i] = NULL;
	return (word);
}

int	main(int ac, char **av)
{
	char	**words;
	int		i;

	if (ac == 1)
		return (0);
	words = ft_split(av[1]);
	if (!words)
		return (1);
	i = -1;
	while (words[++i])
	{
		printf("%s\n", words[i]);
		free (words[i]);
	}
	free (words);
	return (0);
}
