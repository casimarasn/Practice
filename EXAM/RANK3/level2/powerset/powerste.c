#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*

./powerset 5 1 2 3 4 5

que necesitamos?
tamaño_a = tamaño de la lista recibida por argumentos
tamaño_b = tamaño de la lista para imprimir
valor = suma que vamos haciendo
target = el numero objetivo [av[1]]
iterador = iterador de la lista recibida por argumentos
iterador = iterador de la lista para imprimir
result = array de int para imprimir
*/

void print_list(int *list, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d", list[i]);
		if (i != size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int *array_to_int(char **av, int size)
{
	int i = 2, j = 0;
	int *list = malloc(size * sizeof(int));
	if (!list)
		return NULL;
	while (av[i])
	{
		list[j] = atoi(av[i]);
		i++;
		j++;
	}
	return(list);
}

void back_tracking(int size_list, int target, int size_result, int i, int j, int value, int *result, int *list)
{
	if (i == size_list)
	{
		if (value == target)
		{
			print_list(result, size_result);
			return ;
		}
		else
			return;
	}
	result[j] = list[i];
	back_tracking(size_list, target, size_result + 1, i + 1, j + 1, value + result[j], result, list);
	back_tracking(size_list, target, size_result, i + 1, j, value, result, list);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	int	size = ac - 2;
	int target = atoi(av[1]);
	int result[size];
	int *list = array_to_int(av, size);
	back_tracking(size, target, 0, 0, 0, 0, result, list);
	free(list);
	return (0);
}