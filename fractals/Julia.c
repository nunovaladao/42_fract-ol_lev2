/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:33 by nuno              #+#    #+#             */
/*   Updated: 2023/04/15 17:12:29 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void julia_shift(t_julia *j, int x, int y)
{
    j->shift_x = j->min_r + (double)x * (j->max_r - j->min_r) / j->width;
    j->shift_y = j->max_i + (double)y * (j->min_i - j->max_i) / j->height;
    return ;
}

void init_julia(t_julia *j, t_vars *vars)
{
  j->width = vars->width_win;
  j->height = vars->height_win;
  j->count = 0;
  j->zoom = 1;
  j->iter = 100;
  j->min_r = -2;
  j->max_r = j->min_r * -1 * j->width / j->height;
  j->min_i = -2;
  j->max_i = j->min_i * -1 * j->height / j->width;
}

int iter_julia(t_julia *j, double zr, double zi)
{
  double tmp;
  int i;

  i = 0;
  while (i < j->iter)
  {
    if ((zr * zr + zi * zi) > 4)
    {
      j->count = i;
      return(0);
    }
    tmp = zr * zr - zi * zi;
    zi = 2 * zr * zi + j->shift_y;
    zr = tmp + j->shift_x;
    i++;
  }
      j->count = i;
  return (1);
}

void set_julia(t_julia *j, t_data *img, t_vars *vars)
{
  int x;
  int y;
  double pr;
  double pi;

  init_julia(j, vars);
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
  mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}
