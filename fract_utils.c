/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/14 22:56:50 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vars init(void)
{
    t_vars vars;
    
    vars.mlx = NULL;
    vars.win = NULL;

    return (vars);
}

void choose_fractal(char **av, t_vars *vars)
{
    if (ft_strcmp(av[1], "Mandelbrot") == 0)
        vars->fractal = MANDELBROT;
    if (ft_strcmp(av[1], "Julia") == 0)
        vars->fractal = JULIA;
    return ;
}

int run_fractal(t_vars *vars, t_data *img, t_mandelbrot *m, t_julia *j)
{
    if (vars->fractal == MANDELBROT)
        set_mandel(m, img, vars);
    if (vars->fractal == JULIA)
        set_julia(j, img);
    return (0);   
}

void mlx_exit(t_vars *vars)
{
    //mlx_destroy_image(vars->mlx, vars->img.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(EXIT_SUCCESS);
}