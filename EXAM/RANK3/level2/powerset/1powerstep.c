/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1powerstep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:23:59 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/18 19:18:32 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int *array_to_int(char **av, int size)
{
	int *list = malloc(sizeof(int) * size);
	int i = 2; int j = 0;
	while (av[i])
	{
		list[j] = atoi(av[i]);
		j++;
		i++;
	}
	return (list);
}

void print_array(int *res, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d", res[i]);
		if (i != size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void back_tracking(int size, int target, int *res, int size_res, int *list, int value, int i, int j)
{
	if (i == size)
	{
		if (value == target)
		{
			print_array(res, size_res);
			return;
		}
		else	
			return ;
	}
	res[j] = list[i];
	back_tracking(size, target, res, size_res + 1, list, value + res[j], i + 1, j + 1);
	back_tracking(size, target, res, size_res, list, value, i + 1, j);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int size = ac - 2;
	int target = atoi(av[1]);
	int res[size];
	int *list = array_to_int(av, size);
	back_tracking(size, target, res, 0, list, 0, 0, 0);
	free(list);
	return 0;
}
