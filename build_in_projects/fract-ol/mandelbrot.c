/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:02:49 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 18:19:40 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_c c, t_fractal *fractal)
{
	int		i;
	t_c		cc;
	double	aux;

	cc.re = 0.0;
	cc.im = 0.0;
	i = 0;
	while (cc.re * cc.re + cc.im * cc.im <= 4.0 && i < fractal->max_it)
	{
		aux = cc.re * cc.re - cc.im * cc.im + c.re;
		cc.im = 2 * cc.re * cc.im + c.im;
		cc.re = aux;
		i++;
	}
	return (i);
}

t_c	pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_c	c;

	c.re = fractal->min_real + ((double)x / WIDTH)
		* (fractal->max_real - fractal->min_real);
	c.im = fractal->min_imag + ((double)y / HEIGHT)
		* (fractal->max_imag - fractal->min_imag);
	return (c);
}

void	render_mandelbrot(t_fractal *fractal)
{
	t_c			c;
	uint32_t	color;
	int			x;
	int			y;
	int			iter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = pixel_to_complex(x, y, fractal);
			iter = mandelbrot(c, fractal);
			if (iter == fractal->max_it)
				color = BLACK;
			else
				color = get_color(iter, fractal->max_it);
			mlx_put_pixel(fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}
