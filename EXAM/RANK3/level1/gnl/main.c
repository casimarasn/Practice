/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:13:44 by casimarasn        #+#    #+#             */
/*   Updated: 2025/11/10 13:25:38 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	//fd = open("subject.txt", O_RDONLY);
	line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	/*for (int i = 0; i < 3; i++)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}*/
	close(fd);
	return (0);
}