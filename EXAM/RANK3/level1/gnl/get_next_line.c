/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:54:17 by casimarasn        #+#    #+#             */
/*   Updated: 2025/11/11 16:22:51 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#
char	*get_next_line(int fd)
{
	char		*line;
	char		c;
	int			bytes;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	if (bytes < 0 || i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
