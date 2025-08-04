/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                 	                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *str)
{
	char	**word;
	int		i;
	int		j;
	int		start;
	int		count;

	i = 0;
	count = 0;
	word = malloc (1000 * sizeof (char *));
	if (!word)
		return (NULL);
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		word[count] = malloc ((i - start + 1) * sizeof (char));
		if (!word[count])
			return (NULL);
		j = 0;
		while (start < i)
		{
			word[count][j] = str[start];
			start++;
			j++;
		}
		word[count][j] = '\0';
		count++;
	}
	word[count] = NULL;
	return (word);
}

int	main (int	ac, char **av)
{
	char	**words;
	int		i;

	i = 0;
	words = ft_split (av[1]);
	if (ac == 1)
		return (0);
	while (words[i])
	{
		printf("%s\n", words[i]);
		free (words[i]);
		i++;
	}
	free (words);
	return (0);
}
