/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:13:41 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/04 06:28:15 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->image = NULL;
	fractal->type = MANDELBROT;
	fractal->min_real = -2.5;
	fractal->max_real = 1.0;
	fractal->min_imag = -1.25;
	fractal->max_imag = 1.25;
	fractal->zoom = 1.0;
	fractal->max_it = 100;
	if (fractal->type == MANDELBROT)
	{
		fractal->julia_real = 0.0;
		fractal->julia_imag = 0.0;
	}
	else if (fractal->type == JULIA)
	{
		fractal->julia_real = -0.7;
		fractal->julia_imag = 0.27015;
	}
}

void	init_fractal(t_fractal *fractal)
{
	init_values(fractal);
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "puto", 1);
	if (!fractal->mlx)
		return ;
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		finish_exit(fractal);
		return ;
	}
	render_mandelbrot(fractal);
	mlx_loop(fractal->mlx);
	finish_exit(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	(void)ac;
	(void)av;
	init_fractal(&fractal);
	ft_printf("puto ziempre");
	return (0);
}
