/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:13:41 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 23:17:47 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->image = NULL;
	fractal->type = 0;
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->min_imag = -2.0;
	fractal->max_imag = 2.0;
	fractal->zoom = 1.0;
	fractal->max_it = MAX_ITER;
	fractal->julia_real = 0.0;
	fractal->julia_imag = 0.0;
}

void	parse_args(t_fractal *fractal, int ac, char **av, t_atod *atod)
{
	if ((ft_strncmp(av[1], "julia", 5) == 0) && (ft_strlen(av[1]) == 5)
		&& (ac == 2 || ac == 4))
	{
		fractal->type = JULIA;
		fractal->julia_real = -0.7;
		fractal->julia_imag = 0.27015;
		if (ac == 4 && ft_strlen(av[2]) != 0 && ft_strlen(av[3]) != 0)
		{
			fractal->julia_real = ft_atod(av[2], atod);
			fractal->julia_imag = ft_atod(av[3], atod);
		}
	}
	else if ((ft_strncmp(av[1], "mandelbrot", 10)) == 0
		&& (ft_strlen(av[1]) == 10) && (ac == 2))
		fractal->type = MANDELBROT;
	else
		error_message(fractal);
}

void	render_fractols(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
		render_mandelbrot(fractal);
	else if (fractal->type == JULIA)
		render_julia(fractal);
	else
		return ;
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "pfractol", 1);
	if (!fractal->mlx)
		return ;
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		finish_exit(fractal);
		return ;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	mlx_scroll_hook(fractal->mlx, scroll_callback, fractal);
	mlx_loop_hook(fractal->mlx, handle_keys, fractal);
	render_fractols(fractal);
	mlx_loop(fractal->mlx);
	finish_exit(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	t_atod		atod;

	if (ac < 2)
	{
		ft_printf("Error: %s mandelbrot | julia <real> <imag>\n", av[0]);
		return (0);
	}
	init_values(&fractal);
	parse_args(&fractal, ac, av, &atod);
	init_fractal(&fractal);
	return (0);
}
