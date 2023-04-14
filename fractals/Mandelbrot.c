/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/14 15:01:33 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void init_mandel(t_mandelbrot *m, t_vars *vars) 
{
  m->width = vars->width_win;
  m->height = vars->height_win;
  m->count = 0;
  m->zoom = 1;
  m->iter = 100;
  m->min_r = -2;
  m->max_r = m->min_r * -1 * m->width / m->height;
  m->min_i = -2;
  m->max_i = m->min_i * -1 * m->height / m->width;
}

int iter_mandel(t_mandelbrot *m, double cr, double ci)
{
  double zr;
  double zi;
  double tmp;
  int i;

  zr = 0;
  zi = 0;
  i = 0;
  while (i <= m->iter)
  {
    if ((zr * zr + zi * zi) > 4.0)
    {
      m->count = i;
      return(0);
    }
    tmp = 2 * zr * zi + ci;
    zr = zr * zr - zi * zi + cr;
    zi = tmp;
    i++;
  }
      m->count = i;
  return (1);
}

void set_mandel(t_mandelbrot *m, t_data *img, t_vars *vars)
{
  int x;
  int y;
  double pr;
  double pi;

  init_mandel(m, vars);
  y = -1;
  while (++y < m->height)
  {
    pi = m->max_i + (double)y * (m->min_i - m->max_i) / m->height; 
    x = -1;
    while (++x < m->width)
    {
      pr = m->min_r + (double)x * (m->max_r - m->min_r) / m->width;
      if (iter_mandel(m, pr, pi) == 0)
      {
        my_mlx_pixel_put(img, x, y, color(m));
      }
      else
        my_mlx_pixel_put(img, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}
