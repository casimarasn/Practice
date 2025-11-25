/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 05:14:44 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/25 10:25:00 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

int	ft_strlen(char *s)
{
	int res = 0;
	while (s && *s)
	{
		s++;
		res++;
	}
	return (res);
}

int	str_append_mem(char **s1, char *s2, int size2)
{
	int size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	int	j = ft_strlen((char *)src);
	int	i = 0;
	while (i < j)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char *ret = NULL;
	char *tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		if (read_ret == 0)
		{
			if (*ret)
				return (ret);
			free (ret);
			return (NULL);
		}
		tmp = ft_strchr(b, '\n');
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	memmove(b, tmp + 1, ft_strlen(tmp + 1));
	return ret;
}

