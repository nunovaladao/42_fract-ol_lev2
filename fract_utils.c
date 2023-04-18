/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/18 21:36:41 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom_fractal(t_vars *fractal, int x, int y, double zoom)
{
    (void)x;
	(void)y;
	fractal->center_r = fractal->min_r - fractal->max_r;
	fractal->center_i = fractal->max_i - fractal->min_i;
	fractal->max_r = fractal->max_r + (fractal->center_r - zoom * fractal->center_r) / 2;
	fractal->min_r = fractal->max_r + zoom * fractal->center_r;
	fractal->min_i = fractal->min_i + (fractal->center_i - zoom * fractal->center_i) / 2;
	fractal->max_i = fractal->min_i + zoom * fractal->center_i;
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

void	choose_fractal(char **av, t_vars *vars)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		vars->fractal = MANDELBROT;
	if (ft_strcmp(av[1], "Julia") == 0)
		vars->fractal = JULIA;
	return ;
}

int	run_fractal(t_vars *vars, t_data *img)
{
	if (vars->fractal == MANDELBROT)
		set_mandel(img, vars);
	if (vars->fractal == JULIA)
		set_julia(img, vars);
	return (0);
}

void	mlx_exit(t_vars *vars)
{
	//mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
