/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/25 23:08:09 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int iter_mandel(t_vars *m, double cr, double ci)
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

void set_mandel(t_vars *m)
{
  int x;
  int y;
  double pr;
  double pi;

  x = -1;
  while (++x < m->height)
  {
    pr = m->zoom * 2 * (x + m->x_arr - m->height / 2) / (m->height / 2);
    y = -1;
    while (++y < m->width)
    {
      pi = m->zoom * 2 * (y + m->y_arr - m->width / 2) / (m->width / 2);
      if (iter_mandel(m, pr, pi) == 0)
        my_mlx_pixel_put(m, x, y, color_mandel(m));
      else
        my_mlx_pixel_put(m, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}
