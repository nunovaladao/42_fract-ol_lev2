/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:05 by nuno              #+#    #+#             */
/*   Updated: 2023/04/15 16:17:40 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int keycode, t_vars *vars)
{
    //t_data *img;
    double scale;
    double zoom = 1.1;

    if (keycode == SCROLL_UP)
        scale = vars->scale * zoom;
    else if (keycode == SCROLL_DOWN)
        scale = vars->scale / zoom;
    else 
        return (0);
    vars->scale = scale;
    mlx_clear_window(vars->mlx, vars->win);
	return (0);
}

int keyboard_hook(int keycode, t_vars *vars)
{
    if (keycode == ESC)
        mlx_exit(vars);
    return(0);
}

int hook_events(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, (void *)mlx_exit, vars);
    mlx_key_hook(vars->win, &keyboard_hook, vars);
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
    return(0);
}