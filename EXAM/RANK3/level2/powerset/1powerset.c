/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1powerset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:28:35 by casimarasn        #+#    #+#             */
/*   Updated: 2025/11/23 21:13:43 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//atoi, printf, fprintf, malloc, calloc, realloc, free, stdout, write

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*nums;
int	target;
int	actual[100];

void	powerset(int posnums, int size, int posact, int sum)
{
	if (sum == target)
	{
		int	i = 0;
		while (i < posact)
		{
			if (i > 0)
				printf(" ");
			printf("%d", actual[i++]);
		}
		printf("\n");
		return ;
	}
	if ( posnums == size)
		return ;
	powerset(posnums + 1, size, posact, sum);
	actual[posact] = nums[posnums];
	powerset(posnums + 1, size, posact + 1, sum + nums[posnums]);
}

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 3 || !(nums = malloc(sizeof(int) * (ac - 2))))
		return (1);
	target = atoi(av[1]);
	while (++i < ac - 2)
		nums[i] = atoi(av[i + 2]);
	powerset(0, ac - 2, 0, 0);
	free(nums);
	return (0);
}
