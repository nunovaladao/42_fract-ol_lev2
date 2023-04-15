/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/15 15:52:05 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int is_number(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (1);
        str++;
    }    
    return (0);
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
        set_julia(j, img, vars);
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