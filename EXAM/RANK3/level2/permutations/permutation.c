/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:19:01 by msedeno-          #+#    #+#             */
/*   Updated: 2025/11/20 21:57:59 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*Ejercicio 5: permute

📜 Escribe una función que imprima todas las permutaciones posibles
de los números del 1 al n.
Ejemplo:
n = 3
123
132
213
231
312
321
💡 No puedes repetir números, y cada nivel del backtracking
representa una posición en la permutación.*/

void	backtrack(int pos, int n, char *av, char *sol, int *temp)
{
	if (pos == n)
	{
		// for (int i = 0; i < n; i++)
		// 	printf("%c", sol[i]);
		puts(sol);
		// printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!temp[i])
		{
			temp[i] = 1;
			sol[pos] = av[i];
			backtrack(pos + 1, n, av, sol, temp);
			temp[i] = 0;
		}
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	sort(char *str, int n)
{
	int		i;
	char	tmp;

	while (n > 0)
	{
		i = 0;
		while (i < n - 1)
		{
			if (str[i] > str[i + 1])
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
		n--;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int n = ft_strlen(argv[1]);
	char *sol = calloc(sizeof(char) , n);
	int *temp = calloc(sizeof(int), n);
	sort(argv[1], n);
	backtrack(0, n, argv[1] ,sol, temp);
	free(sol);
	free(temp);
	return(0);
}





// void	backtrack(int pos, int n, char *str, char *sol, int *used)
// {
// 	if (pos == n)
// 	{
// 		sol[n] = '\0';
// 		printf("%s\n", sol);
// 		return ;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (!used[i])
// 		{
// 			used[i] = 1;
// 			sol[pos] = str[i];
// 			backtrack(pos + 1, n, str, sol, used);
// 			used[i] = 0;
// 		}
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);

// 	char *input = argv[1];
// 	int n = ft_strlen(input);
// 	char sol[n + 1];
// 	int used[n];

// 	for (int i = 0; i < n; i++)
// 		used[i] = 0;
// 	sort(input, n);
// 	backtrack(0, n, input, sol, used);
// 	return (0);
// }
