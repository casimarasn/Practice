/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:31:47 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/21 23:14:46 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	res;

	res = 0;
	if (argc == 4 && argv[2][1] == '\0')
	{
		if (argv[2][0] == '+')
			res = atoi(argv[1]) + atoi(argv[3]);
		else if (argv[2][0] == '-')
			res = atoi(argv[1]) - atoi(argv[3]);
		else if (argv[2][0] == '*')
			res = atoi(argv[1]) * atoi(argv[3]);
		else if (argv[2][0] == '/')
			res = atoi(argv[1]) / atoi(argv[3]);
		else if (argv[2][0] == '%')
			res = atoi(argv[1]) % atoi(argv[3]);
		else
			return (1);
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
