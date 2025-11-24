/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2powerset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:38:28 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/24 21:40:12 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	target;
int	*nums;
int	factors[100];

void	powerset(int posnums, int size, int posfactors, int sum)
{
	if (sum == target)
	{
		int	i = 0;
		while (i < posfactors)
		{
			if (i > 0)
				printf (" ");
			printf ("%d", factors[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	if (posnums == size)
		return ;
	powerset(posnums + 1, size, posfactors, sum);
	factors[posfactors] = nums[posnums];
	powerset(posnums + 1, size, posfactors + 1, sum + nums[posnums]);
}

int	main(int ac, char **av)
{
	if (ac < 3 || !(nums = malloc(sizeof(int) * (ac -2))))
		return (1);
	target = atoi(av[1]);
	int	i = 0;
	while(i < ac - 2)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(0, ac + 2, 0, 0);
	free(nums);
	return(0);
}

