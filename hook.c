/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:05 by nuno              #+#    #+#             */
/*   Updated: 2023/03/30 19:05:20 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int keycode, t_vars *vars)
{
    (void)keycode;
    (void)vars;
    printf("Mouse here!\n");
	return (0);
}

int keyboard_hook(int keycode, t_vars *vars)
{
    if (keycode == ESC)
    {
        mlx_destroy_image(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
    }
    free(vars->mlx);
    return(0);
}

int hook_events(t_vars *vars)
{
    mlx_key_hook(vars->win, &keyboard_hook, vars);
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &keyboard_hook, vars);
    return(0);
}