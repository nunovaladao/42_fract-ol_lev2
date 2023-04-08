/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:08:40 by nuno              #+#    #+#             */
/*   Updated: 2023/04/08 13:14:41 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void init_mlx(t_vars *vars)
{
    vars->mlx = mlx_init();
    
    if (!vars->mlx)
    {
        solve_errors("Inicialize error!");
        exit(1);
    }
    vars->win = mlx_new_window(vars->mlx, vars->height_win, vars->width_win, "Fract-ol!");
    if (!vars->win)
    {
        solve_errors("Inicialize window error!");
        free(vars->win);
        free(vars->mlx);
        exit(1);
    }
}

void init_window(t_vars *vars, t_data *img)
{
    img->img = mlx_new_image(vars->mlx, vars->height_win, vars->width_win);
    if (!img->img)
    {
        solve_errors("Init image error!");
        free(vars->win);
        free(vars->mlx);
        free(img->img);
        exit(1);
    }
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
    if (!img->addr)
    {
        solve_errors("Init image error!");
        free(vars->win);
        free(vars->mlx);
        free(img->img);
        free(img->addr);
        exit(1);
    }
	my_mlx_pixel_put(img, 0, 0, 0x0000FF00);
}