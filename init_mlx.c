/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:08:40 by nuno              #+#    #+#             */
/*   Updated: 2023/04/14 19:45:51 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(char **av, t_vars *vars, t_data *img)
{
    vars->mlx = mlx_init();
    if (ft_strcmp(av[1], "Mandelbrot") == 0)
        vars->win = mlx_new_window(vars->mlx, vars->width_win, vars->height_win, "Mandelbrot");
    if (ft_strcmp(av[1], "Julia") == 0)
        vars->win = mlx_new_window(vars->mlx, vars->width_win, vars->height_win, "Julia");
    img->img = mlx_new_image(vars->mlx, vars->width_win, vars->height_win);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}
