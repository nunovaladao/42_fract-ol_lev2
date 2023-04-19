/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:05 by nuno              #+#    #+#             */
/*   Updated: 2023/04/19 11:53:43 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, t_vars *fractal, t_data *img, int x, int y)
{
    (void)x;
    (void)y;
    if (fractal->fractal == MANDELBROT)
    {
        if (keycode == SCROLL_UP)
            fractal->zoom *= 1.1;
        if (keycode == SCROLL_DOWN)
            fractal->zoom /= 1.1;
        set_mandel(img, fractal);
    }
    if (fractal->fractal == JULIA)
    {
        if (keycode == SCROLL_UP)
            fractal->zoom *= 1.1;
        if (keycode == SCROLL_DOWN)
            fractal->zoom /= 1.1;
        set_julia(img, fractal);
    }
	return (0);
}

int	keyboard_hook(int keycode, t_vars *fractal)
{
	if (keycode == ESC)
		mlx_exit(fractal);
	return (0);
}

int	hook_events(t_vars *fractal)
{
	mlx_hook(fractal->win, 17, 0, (void *)mlx_exit, fractal);
	mlx_key_hook(fractal->win, &keyboard_hook, fractal);
	mlx_mouse_hook(fractal->win, &mouse_hook, (void*)fractal);
	return (0);
}
