
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
pos = columna
size = tamaño del tablero
value = nnumero
board = tablero

3 2 5 1

*/
void	*print_array(int *board, int size)
{
	int	i = 0;
	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i != size - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_valid(int *board, int pos, int value)
{
	
}
void n_queen(int pos, int size, int value, int *board)
{
	if (pos == size)
	{
		print_array(board, size);
		return ;
	}

}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (atoi(av[1]) < 4)
	{
		fprintf(stdout, "\n");
		return (0);
	}
	int board[atoi(av[1])];
}