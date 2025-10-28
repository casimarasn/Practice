/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:11:40 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/04 06:27:22 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

/* Window dimensions */
# define WIDTH 1920
# define HEIGHT 1080

/* Math constants */
# define MAX_ITER 100
# define ZOOM_FACTOR 1.2
# define MOVE_STEP 0.1

/* Color constants */
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

// ./errors_free.c
void	finish_exit(t_fractal *fractal);

// ./fractol.c
void	init_values(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
int		main(int ac, char **av);

// ./julia.c

// ./mandelbrot.c
int		mandelbrot(t_c c, t_fractal *fractal);
void	render_mandelbrot(t_fractal *fractal);


#endif