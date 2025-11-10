/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 23:01:00 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:22 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom centrado en (mx,my) en píxeles; factor < 1 = zoom in, > 1 = zoom out */
void	zoom_at(t_fractal *fractal, double mx, double my, double factor)
{
	double	cx;
	double	cy;
	double	new_w;
	double	new_h;

	cx = fractal->min_real + (mx / (double)WIDTH)
		* (fractal->max_real - fractal->min_real);
	cy = fractal->min_imag + (my / (double)HEIGHT)
		* (fractal->max_imag - fractal->min_imag);
	new_w = (fractal->max_real - fractal->min_real) * factor;
	new_h = (fractal->max_imag - fractal->min_imag) * factor;
	fractal->min_real = cx - (mx / (double)WIDTH) * new_w;
	fractal->max_real = fractal->min_real + new_w;
	fractal->min_imag = cy - (my / (double)HEIGHT) * new_h;
	fractal->max_imag = fractal->min_imag + new_h;
}

/* Scroll callback: ajusta zoom y redibuja */
void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	int32_t		mx_i;
	int32_t		my_i;
	double		factor;

	(void)xdelta;
	f = (t_fractal *)param;
	if (!f || !f->mlx)
		return ;
	mlx_get_mouse_pos(f->mlx, &mx_i, &my_i);
	if (ydelta > 0)
		factor = 1.1 / ZOOM_FACTOR;
	else
		factor = ZOOM_FACTOR;
	zoom_at(f, (double)mx_i, (double)my_i, factor);
	render_fractols(f);
}

static int	move_horizontal(t_fractal *f)
{
	int	updated;

	updated = 0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(f->mlx, MLX_KEY_A))
	{
		pan_view(f, -0.05, 0.0);
		updated = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(f->mlx, MLX_KEY_D))
	{
		pan_view(f, 0.05, 0.0);
		updated = 1;
	}
	return (updated);
}

static int	move_vertical(t_fractal *f)
{
	int	updated;

	updated = 0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(f->mlx, MLX_KEY_W))
	{
		pan_view(f, 0.0, -0.05);
		updated = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(f->mlx, MLX_KEY_S))
	{
		pan_view(f, 0.0, 0.05);
		updated = 1;
	}
	return (updated);
}

void	handle_keys(void *param)
{
	t_fractal	*f;
	int			updated;

	f = (t_fractal *)param;
	if (!f || !f->mlx)
		return ;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	updated = 0;
	updated += move_horizontal(f);
	updated += move_vertical(f);
	if (f->type == JULIA)
		julia_controls(f);
	else if (updated)
		render_fractols(f);
}
