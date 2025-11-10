/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:36:58 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/09 19:59:20 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(int iter, int max_iter)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	ratio = (double)iter / max_iter;
	r = 255;
	b = 0;
	g = 0;
	if (ratio < 0.25)
		r = (int)(255 * ratio * 4);
	else if (ratio < 0.5)
		g = (int)(255 * (ratio - 0.25) * 4);
	else if (ratio < 0.75)
	{
		g = 128 + (int)(127 * (ratio - 0.5) * 4);
		b = (int)(100 * (ratio - 0.5) * 4);
	}
	else
	{
		g = 255;
		b = (int)(255 * (ratio - 0.75) * 4);
	}
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
