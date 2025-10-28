/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:03:16 by casimarasn        #+#    #+#             */
/*   Updated: 2025/05/14 11:52:37 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	dlimit;
	int	words;

	dlimit = 1;
	words = 0;
	while (s && *s)
	{
		if (*s == c)
			dlimit = 1;
		else if (*s != c && dlimit)
		{
			dlimit = 0;
			words++;
		}
		s++;
	}
	return (words);
}

static int	ft_fillar(char **list, char const *str, int wcount, char c)
{
	int	i;
	int	wlen;

	i = 0;
	wlen = 0;
	while (wcount -- && str && *str)
	{
		while (*str == c)
			str++;
		while (str[wlen] && str[wlen] != c)
			wlen ++;
		list[i] = ft_substr(str, 0, wlen);
		if (!list[i])
		{
			while (i--)
				free(list[i]);
			free(list);
			return (0);
		}
		str += wlen + 1;
		wlen = 0;
		i++;
	}
	list[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wcount;
	char	**result;

	if (!s)
		return (NULL);
	wcount = ft_wordcount (s, c);
	result = malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (NULL);
	if (!ft_fillar(result, s, wcount, c))
		return (NULL);
	return (result);
}
