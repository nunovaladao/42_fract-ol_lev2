/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/13 19:00:23 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void init_mandel(t_mandelbrot *m, t_vars *vars) 
{
  m->width = vars->width_win;
  m->height = vars->height_win;
  m->zoom = 1;
  m->iter = 25;
  m->min_r = -2;
  m->max_r = m->min_r * -1 * vars->width_win / vars->height_win;
  m->min_i = -2;
  m->max_i = m->min_i * -1 * vars->height_win / vars->width_win;
}

int iter_mandel(t_mandelbrot m, double cr, double ci)
{
  double zr;
  double zi;
  double tmp;
  int i;

  zr = 0;
  zi = 0;
  i = 0;
  while (i <= m.iter + m.resulotion)
  {
    if ((zr * zr + zi * zi) > 4.0)
    {
      m.count = i;
      return(0);
    }
    tmp = 2 * zr * zi + ci;
    zr = zr * zr - zi * zi + cr;
    zi = tmp;
    i++;
  }
      m.count = i;
  return (1);
}

void set_mandel(t_mandelbrot m, t_data *img, t_vars *vars)
{
  int x;
  int y;
  double pr;
  double pi;

  y = -1;
  init_mandel(&m, vars);
  while (++y < m.height)
  {
    pi = m.max_i + (double)y * (m.min_i - m.max_i) / m.height; 
    x = -1;
    while (++x < m.width)
    {
      pr = m.min_r + (double)x * (m.max_r - m.min_r) / m.width;
      if (iter_mandel(m, pr, pi) == 0)
        my_mlx_pixel_put(img, x, y, 0x000000);
      else
        my_mlx_pixel_put(img, x, y, 0xFFFFFF);
    }
  }
  mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}
