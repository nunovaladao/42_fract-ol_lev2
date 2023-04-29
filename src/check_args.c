/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:27 by nuno              #+#    #+#             */
/*   Updated: 2023/04/29 20:08:13 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	display_mensg(int options)
{
	if (options == 0)
	{
		ft_printf("Run:\n\n");
		ft_printf("  1) ./fractol <fractal>\n\n");
		ft_printf("  2) For Julia you can set diferent");
		ft_printf(" paramaters to change the fractal:\n");
		ft_printf("\t2.1) ./fractol <fractal> cx cy\n\n");
		ft_printf("Note: pick some values (between -2 and 2) for the ");
		ft_printf("constant c, this determines the shape of the Julia Set!\n\n");
		ft_printf("Fractal options:\n\n");
		ft_printf("  - Julia\n  - Mandelbrot\n");
		exit(EXIT_FAILURE);
	}
	if (options == 1)
	{
		ft_printf("Options:\n");
		ft_printf("\t- You can do ZOOM_IN and ZOOM_OUT!\n");
		ft_printf("\t- Click on ESC or on the cross for leave!\n");
	}
	if (options == 2)
	{
		ft_printf("Put the right number size:\n\n");
		ft_printf("\t- cx & cy between -2 and 2\n\n");
		exit(EXIT_FAILURE);
	}
}

void	check_julia(int ac, char **av)
{
	if (ac == 4 && ft_strcmp(av[1], "Julia") == 0 \
	&& is_double(av[2]) == 1 && is_double(av[3]) == 1)
	{
		if (valid_size(av, 'x') && valid_size(av, 'y'))
			display_mensg(1);
		else
			display_mensg(2);
	}
	else
	{
		ft_printf("Try again! Check and put the right 'arg' values!\n\n");
		display_mensg(0);
	}
}

void	check_args(int ac, char **av)
{
	if (ac == 1)
		display_mensg(0);
	else if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], \
		"Mandelbrot") == 0)
			display_mensg(1);
		else
		{
			ft_printf("Try again! Check and put the right 'arg' values!\n\n");
			display_mensg(0);
		}
	}
	else if (ac == 4)
		check_julia(ac, av);
	else
	{
		ft_printf("Try again! Check and put the right 'arg' values!\n\n");
		display_mensg(0);
	}
}
