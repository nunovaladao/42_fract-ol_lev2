/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:27 by nuno              #+#    #+#             */
/*   Updated: 2023/04/14 22:58:23 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int input_window(char **av, char x)
{
    int i;
    int size_win;

    i = 1;
    size_win = 0;
    while (av[++i])
    {
        if ((x == 'w' && (i == 2)) || (x == 'h' && (i == 3)))
        {
            size_win = ft_atoi(av[i]);
            break;
        }
    }
    if (!size_win)
        return (0);
    if ((x = 'h') && (size_win > 0 && size_win <= 1080))
        return (size_win);
    else if ((x = 'w') && (size_win > 0 && size_win <= 1980))
        return (size_win);
    else
    {
        ft_printf("Put the right window size!\n\n");
        ft_printf("width: 0 - 1980 and height: 0 - 1080\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}

int window_size(char **av, t_vars *vars)
{
    vars->width_win = input_window(av, 'w');
    if (!vars->width_win)
        vars->width_win = I_WIDTH;
    vars->height_win = input_window(av, 'h');
    if (!vars->height_win)
        vars->height_win = I_HEIGHT;
    return (0);
}

void display_mensg(int options)
{
    if (options == 0)
    {
        ft_printf("Run:\n\n");
        ft_printf("  1) ./fractol <fractal>\n");
        ft_printf("  2) ./fractol <fractal> size_height size_width\n\n");
        ft_printf("Fractal options:\n\n");
        ft_printf("  - Julia\n  - Mandelbrot\n");
    }
    if (options == 1)
    {
        ft_printf("Options:\n");
        ft_printf("\t- Click on ESC or on the cross for leave!\n");
        ft_printf("\t- You also can do ZOOM_IN and ZOOM_OUT!\n");
    }
}

int check_args(int ac, char **av, t_vars *vars)
{
    if (ac == 1 || ac == 3)
    {
        display_mensg(0);
        exit(0);
    }
    if (ac == 2 || ac == 4)
    {
        if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
        {
            window_size(av, vars);
            display_mensg(1);
        }
        else
        {
            ft_printf("Error, put the right name!\n\n");
            display_mensg(0);
            exit(0); 
        }
    }
    return (0);
}