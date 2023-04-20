/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:33 by nuno              #+#    #+#             */
/*   Updated: 2023/04/20 12:53:26 by nsoares-         ###   ########.fr       */
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
    if ((zr * zr + zi * zi) > 4)
    {
      j->count = i;
      return(0);
    }
    tmp = zr * zr - zi * zi;
    zi = 2 * zr * zi + j->c_i;
    zr = tmp + j->c_r;
  }
      j->count = i;
  return (1);
}

void set_julia(t_data *img, t_vars *j)
{
  int x;
  int y;
  double pr;
  double pi;
  
  y = -1;
  while (++y < j->height)
  {
    pi = j->zoom * 2 * (y + j->y_arr - j->height / 2) / (j->height / 2);
    x = -1;
    while (++x < j->width)
    {
      pr = j->zoom * 2 * (x + j->x_arr - j->width / 2) / (j->width / 2);
      if (iter_julia(j, pr, pi) == 0)
        my_mlx_pixel_put(img, x, y, color_julia(j));
      else
        my_mlx_pixel_put(img, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(j->mlx, j->win, img->img, 0, 0);
  mlx_destroy_image(j->mlx, img->img);
}
