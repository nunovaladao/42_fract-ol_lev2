/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:08:40 by nuno              #+#    #+#             */
/*   Updated: 2023/04/25 23:09:09 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(int ac ,char **av, t_vars *fractal)
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
	fractal->img = mlx_new_image(fractal->mlx, I_WIDTH, I_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, \
	&fractal->line_length, &fractal->endian);
	if (fractal->fractal == MANDELBROT)
		init_mandel(fractal);
	if (fractal->fractal == JULIA)
		init_julia(ac, av, fractal);
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

void init_julia(int ac, char **av, t_vars *fractal)
{
  fractal->width = I_WIDTH;
  fractal->height = I_HEIGHT;
  fractal->zoom = 1.0;
  fractal->count = 0;
  fractal->iter = 100;
  fractal->x_arr = 0;
  fractal->y_arr = 0;
  fractal->c_i = ft_atod(av[2]);
  if (!fractal->c_i && ac == 2)
	fractal->c_i = C_I;
  fractal->c_r = ft_atod(av[3]);
  if (!fractal->c_r && ac == 2)
	fractal->c_r = C_R;
}
