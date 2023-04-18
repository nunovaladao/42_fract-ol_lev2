/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:33 by nuno              #+#    #+#             */
/*   Updated: 2023/04/18 21:05:06 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void julia_shift(t_vars *j, int x, int y)
{
    j->shift_x = j->min_r + (double)x * (j->max_r - j->min_i) / j->width;
    j->shift_y = j->max_i + (double)y * (j->min_i - j->max_i) / j->height;
    return ;
}

void init_julia(t_vars *j)
{
  j->width = j->width_win;
  j->height = j->height_win;
  j->count = 0;
  j->iter = 15;
  j->min_r = -2;
  j->max_r = j->min_r * -1 * j->width / j->height;
  j->min_i = -2;
  j->max_i = j->min_i * -1 * j->height / j->width;
  j->shift_x = 0;
  j->shift_y = 0;
}

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
    zi = 2 * zr * zi + j->shift_y;
    zr = tmp + j->shift_x;
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
  
  init_julia(j);
  y = -1;
  while (++y < j->height)
  {
    pi = j->max_i + (double)y * (j->min_i - j->max_i) / j->height; 
    x = -1;
    while (++x < j->width)
    {
      pr = j->min_r + (double)x * (j->max_r - j->min_r) / j->width;
      if (iter_julia(j, pr, pi) == 0)
        my_mlx_pixel_put(img, x, y, color_julia(j));
      else
        my_mlx_pixel_put(img, x, y, 0x000000);
    }
  }
  mlx_put_image_to_window(j->mlx, j->win, img->img, 0, 0);
}
