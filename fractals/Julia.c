/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:33 by nuno              #+#    #+#             */
/*   Updated: 2023/04/26 19:07:33 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int iter_julia(t_vars *j, double zr, double zi)
{
  double tmp;
  int i;
  
  i = 0;
  while (i++ < j->iter)
  {
    tmp = (2 * zr * zi) + j->c_i;
    zr = (zr * zr - zi * zi) + j->c_r;
    zi = tmp;
    if ((zr * zr + zi * zi) > 4.0)
    {
      j->count = i;
      return(0);
    }
  }
      j->count = i;
  return (1);
}

void set_julia(t_vars *j)
{
  int x;
  int y;
  double pr;
  double pi;
  
  x = -1;
  while (++x < j->height)
  {
    pr = j->zoom * 2 * (x - j->height / 2) / (j->height / 2);
    y = -1;
    while (++y < j->width)
    {
      pi = j->zoom * 2 * (y - j->width / 2) / (j->width / 2);
      if (iter_julia(j, pr, pi) == 0)
        my_mlx_pixel_put(j, x, y, color_julia(j));
      else
        my_mlx_pixel_put(j, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(j->mlx, j->win, j->img, 0, 0);
}
