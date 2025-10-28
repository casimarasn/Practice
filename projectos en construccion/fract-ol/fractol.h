/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:11:40 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 23:23:59 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdint.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

/* Window dimensions */
# define WIDTH 1920
# define HEIGHT 1080

/* Math constants */
# define MAX_ITER 500
# define ZOOM_FACTOR 1.2
# define MOVE_STEP 0.1

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF

/* Fractal types */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_c
{
	double	re;
	double	im;
}				t_c;

typedef struct fractal
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			type;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	double		zoom;
	double		julia_real;
	double		julia_imag;
	int			max_it;
}				t_fractal;

typedef struct s_atod
{
	double		frac;
	double		base;
	double		val;
	const char	*paki;
	int			point;
}				t_atod;

// ./args_utils.c
const char	*skip_ws_sign(const char *s, int *sign);
double		parse_fraction(const char *s, t_atod *atod);
double		ft_atod(const char *s, t_atod *atod);

// ./colors.c
uint32_t	get_color(int iter, int max_iter);

// ./errors_free.c
void		finish_exit(t_fractal *fractal);
void		error_message(t_fractal *fractal);

// ./fractol.c
void		init_values(t_fractal *fractal);
void		render_fractols(t_fractal *fractal);
void		init_fractal(t_fractal *fractal);
int			main(int ac, char **av);

// ./julia.c
void		pan_view(t_fractal *f, double dx, double dy);
void		julia_controls(t_fractal *f);
int			julia_iter(t_c cc, t_fractal *fractal);
void		render_julia(t_fractal *fractal);
t_c			pixel_to_complex(int x, int y, t_fractal *fractal);

// ./mandelbrot.c
int			mandelbrot(t_c c, t_fractal *fractal);
void		render_mandelbrot(t_fractal *fractal);

// ./utils.c
void		zoom_at(t_fractal *fractal, double mx, double my, double factor);
void		scroll_callback(double xdelta, double ydelta, void *param);
void		handle_keys(void *param);

#endif
