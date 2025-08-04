/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c               		                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr (int nbr)
{
	char	c;
	if (nbr >=10)
		ft_putnbr (nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main (int ac, char **av)
{
	if(ac == 2)
	{
		ft_putnbr (atoi(av[1]));
	}
	write (1, "\n", 1);
	return (0);
}
