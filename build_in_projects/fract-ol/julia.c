/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:51:14 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 19:59:40 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_view(t_fractal *f, double dx, double dy)
{
	double	w;
	double	h;

	w = f->max_real - f->min_real;
	h = f->max_imag - f->min_imag;
	f->min_real += dx * w;
	f->max_real += dx * w;
	f->min_imag += dy * h;
	f->max_imag += dy * h;
}

void	julia_controls(t_fractal *f)
{
	double	step;
	int		changed;

	step = 0.01;
	changed = 0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Z))
		f->julia_real -= step;
	if (mlx_is_key_down(f->mlx, MLX_KEY_X))
		f->julia_real += step;
	if (mlx_is_key_down(f->mlx, MLX_KEY_C))
		f->julia_imag -= step;
	if (mlx_is_key_down(f->mlx, MLX_KEY_V))
		f->julia_imag += step;
	changed = 1;
	if (changed)
		render_fractols(f);
}

int	julia(t_c c, t_fractal *fractal)
{
	int		i;
	double	tmp;
	t_c		cc;

	cc.re = fractal->julia_real;
	cc.im = fractal->julia_imag;
	i = 0;
	while (c.re * c.re + c.im * c.im <= 4.0 && i < fractal->max_it)
	{
		tmp = c.re * c.re - c.im * c.im + cc.re;
		c.im = 2 * c.re * c.im + cc.im;
		c.re = tmp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractal *fractal)
{
	t_c			c;
	uint32_t	color;
	int			x;
	int			y;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(x, y, fractal);
			iter = julia(c, fractal);
			if (iter == fractal->max_it)
				color = BLACK;
			else
				color = get_color(iter, fractal->max_it);
			mlx_put_pixel(fractal->image, x, y, color);
			x++;
		}
		y++;
	}
}
