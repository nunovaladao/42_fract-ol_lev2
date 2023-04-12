/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/12 15:39:38 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void set_mandel(t_data *img, int max_iter)
{
  //t_mandelbrot m;
  int row;
  int col;

  row = 0;
  col = 0;
  while (row < I_HEIGHT)
  {
    while (col < I_WIDTH)
    {
      double c_re = (col - I_WIDTH / 2.0) * 4.0 / I_WIDTH;
      double c_im = (row - I_HEIGHT / 2.0) * 4.0 / I_HEIGHT;
      double x = 0, y = 0;
      int iter = 0;
      while (x * x + y * y <= 4 && iter < max_iter)
      {
        double tmp = x * x - y * y + c_re;
        y = 2 * x * y + c_im;
        x = tmp;
        iter++;
      }
      if (iter < max_iter)
        my_mlx_pixel_put(img, col, row, 0x000000);
      else
        my_mlx_pixel_put(img, col, row, 0xFFFFFF);
      col++; 
    }
    row++;
  }
}
