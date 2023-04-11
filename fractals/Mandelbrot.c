/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:43 by nuno              #+#    #+#             */
/*   Updated: 2023/04/10 18:01:31 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot_iteration(t_complex c, int max_iter)
{
  t_complex	z;
  double	temp;
  int		iter;

  z.r = 0;
  z.i = 0;
  iter = 0;
  while (z.r * z.r + z.i * z.i <= 4 && iter < max_iter)
  {
    temp = z.r * z.r - z.i * z.i + c.r;
    z.i = 2 * z.r * z.i + c.i;
    z.r = temp;
    iter++;
  }
  return (iter);
}

void	draw_mandelbrot(t_mandelbrot *m, t_vars *vars, t_data *img)
{
  m->y = 0;
  while (m->y < I_HEIGHT)
  {
    m->x = 0;
    while (m->x < I_WIDTH)
    {
      mandelbrot_iteration((t_complex){m->min.r + m->x * m->factor.r,
      							m->min.i + m->y * m->factor.i}, m->max_iter);
      /* if (iter == m->max_iter)
        color = 0;
      else
        color = iter * 255 / m->max_iter; */
      m->x++;
    }
    m->y++;
  }
  mlx_put_image_to_window(vars->mlx, vars->win, img->img, m->x, m->y);
}