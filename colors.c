/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:07:53 by nuno              #+#    #+#             */
/*   Updated: 2023/04/25 22:58:30 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_mandel(t_vars *m)
{
	int	r;
	int	g;
	int	b;

	r = (m->count * 3) % 256;
	g = (m->count * 7) % 256;
	b = (m->count * 9) % 256;
	return (create_trgb(0, r, g, b));
}

int color_julia(t_vars *j)
{
  	int	r;
	int	g;
	int	b;

	r = (j->count * 5) % 256;
	g = (j->count * 20) % 256;
	b = (j->count * 20) % 256;
	return (create_trgb(0, r, g, b));
}

