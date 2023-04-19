/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:08:40 by nuno              #+#    #+#             */
/*   Updated: 2023/04/19 23:11:53 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(char **av, t_vars *fractal, t_data *img)
{
	fractal->mlx = mlx_init();
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
	{
		fractal->win = mlx_new_window(fractal->mlx, I_WIDTH, \
		I_HEIGHT, "Mandelbrot");
		fractal->fractal = MANDELBROT;
	}
	if (ft_strcmp(av[1], "Julia") == 0)
	{
		fractal->win = mlx_new_window(fractal->mlx, I_WIDTH, \
		I_HEIGHT, "Julia");
		fractal->fractal = JULIA;
	}
	img->img = mlx_new_image(fractal->mlx, I_WIDTH, I_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	if (fractal->fractal == MANDELBROT)
		init_mandel(fractal);
	if (fractal->fractal == JULIA)
		init_julia(fractal);
}

void init_mandel(t_vars *fractal)
{
  fractal->width = I_WIDTH;
  fractal->height = I_HEIGHT;
  fractal->zoom = 1.0;
  fractal->count = 0;
  fractal->iter = 100;
  fractal->x_arr = 0;
  fractal->y_arr = 0;
}

void init_julia(t_vars *fractal)
{
  fractal->width = I_WIDTH;
  fractal->height = I_HEIGHT;
  fractal->zoom = 1.0;
  fractal->count = 0;
  fractal->iter = 100;
  fractal->x_arr = 0;
  fractal->y_arr = 0;
  //fractal->c_i = ft_atod(av[2]);
  //fractal->c_r = ft_atod(av[3]);
  fractal->c_i = 0.20015;
  fractal->c_r = -1.1;
}
