/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/19 12:14:24 by nuno             ###   ########.fr       */
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

void set_mandel(t_data *img, t_vars *m)
{
  int x;
  int y;
  double pr;
  double pi;

  y = -1;
  while (++y < m->height)
  {
    pi = m->zoom * 2 * (y + m->y_arr - m->height / 2) / (m->height / 2);
    x = -1;
    while (++x < m->width)
    {
      pr = m->zoom * 2 * (x + m->x_arr - m->width / 2) / (m->width / 2);
      if (iter_mandel(m, pr, pi) == 0)
        my_mlx_pixel_put(img, x, y, color_mandel(m));
      else
        my_mlx_pixel_put(img, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(m->mlx, m->win, img->img, 0, 0);
  mlx_destroy_image(m->mlx, img->img);
}
