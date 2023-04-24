/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:27 by nuno              #+#    #+#             */
/*   Updated: 2023/04/24 09:53:16 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_mensg(int options)
{
	if (options == 0)
	{
		ft_printf("Run:\n\n");
		ft_printf("  1) ./fractol <fractal>\n");
		ft_printf("  2) ./fractol <fractal> size_width size_height\n\n");
		ft_printf("Fractal options:\n\n");
		ft_printf("  - Julia\n  - Mandelbrot\n");
		exit(EXIT_SUCCESS);
	}
	if (options == 1)
	{
		ft_printf("Options:\n");
		ft_printf("\t- Click on ESC or on the cross for leave!\n");
		ft_printf("\t- You also can do ZOOM_IN and ZOOM_OUT!\n");
	}
	if (options == 2)
	{
		ft_printf("Put the right window size!\nPut only numbers!\n\n");
		ft_printf("width: 0 - 1980 and height: 0 - 1080\n");
		exit(EXIT_FAILURE);
	}
}

void	check_args(int ac, char **av)
{
	if (ac == 1)
		display_mensg(0);
	else if (ac == 2 || ac == 4)
	{
		if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], \
		"Mandelbrot") == 0)
		{
			if (ac == 4 && ft_strcmp(av[1], "Julia") == 0 && is_double(av[2]) == 1 && is_double(av[3]) == 1)
            {
                if (valid_size(av) == true && valid_size(av) == true)
				    display_mensg(1);
                else 
                    display_mensg(2);
            }
			else
				display_mensg(1);
		}
		else
		{
			ft_printf("Error, put the right name!\n\n");
			display_mensg(0);
		}
	}
    else
        return (display_mensg(0));
}