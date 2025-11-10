/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:32:38 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/07 17:58:50 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	finish_exit(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_terminate(fractal->mlx);
	exit(EXIT_FAILURE);
}

void	error_message(t_fractal *fractal)
{
	if (fractal && (fractal->type != MANDELBROT || fractal->type != JULIA))
		ft_putstr_fd("err: ./fractol mandelbrot | julia <real> <imag>\n", 2);
	exit(EXIT_FAILURE);
}
