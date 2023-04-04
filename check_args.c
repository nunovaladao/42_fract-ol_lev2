/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:27 by nuno              #+#    #+#             */
/*   Updated: 2023/04/05 00:02:28 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void display_mensg(int options)
{
    if (options == 0)
    {
        ft_printf("Choose this two fractals:\n");
        ft_printf("- Julia\n- Mandelbrot\n");
    }
    if (options == 1)
    {
        ft_printf("Options:\n");
        ft_printf("\t- Click on ESC or on the cross for leave!\n");
        ft_printf("\t- You also can do ZOOM_IN and ZOOM_OUT!\n");
    }
}

int check_args(int ac, char **av)
{
    if (ac == 1)
    {
        display_mensg(0);
        exit(0);
    }
    if (ac == 2)
    {
        if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
            display_mensg(1);
        else
        {
            ft_printf("Error, put the right name!\n\n");
            display_mensg(0);
            exit(0); 
        }
    }
    return (0);
}