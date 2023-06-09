/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:05 by nuno              #+#    #+#             */
/*   Updated: 2023/04/27 11:38:11 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int keycode, int x, int y, t_vars *fractal)
{
	(void)x;
	(void)y;
	if (fractal->fractal == MANDELBROT)
	{
		if (keycode == SCROLL_UP)
			fractal->zoom /= 1.2;
		else if (keycode == SCROLL_DOWN)
			fractal->zoom *= 1.2;
		set_mandel(fractal);
	}
	if (fractal->fractal == JULIA)
	{
		if (keycode == SCROLL_UP)
			fractal->zoom /= 1.2;
		else if (keycode == SCROLL_DOWN)
			fractal->zoom *= 1.2;
		set_julia(fractal);
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
	mlx_mouse_hook(fractal->win, &mouse_hook, fractal);
	return (0);
}
