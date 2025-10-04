/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:32:38 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/03 20:59:43 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	finish_exit(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_terminate(fractal->mlx);
	exit(EXIT_FAILURE);
}
