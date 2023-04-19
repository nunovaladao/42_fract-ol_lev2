/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:27 by nuno              #+#    #+#             */
/*   Updated: 2023/04/19 23:12:32 by nuno             ###   ########.fr       */
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

int	input_window(char **av, char x)
{
	int	i;
	double	size_win;

	i = 1;
	size_win = 0;
	while (av[++i])
	{
		if ((x == 'w' && (i == 2)) || (x == 'h' && (i == 3)))
		{
			size_win = ft_atod(av[i]);
			break ;
		}
	}
	if (!size_win)
		return (0);
	return (size_win);
	//display_mensg(2);
}

int	window_size(char **av, t_vars *fractal)
{
	fractal->c_r = input_window(av, 'w');
	if (!fractal->c_r)
		fractal->c_r = C_R;
	fractal->c_i = input_window(av, 'h');
	if (!fractal->c_i)
		fractal->c_i = C_I;
	return (0);
}

void	check_args(int ac, char **av/* , t_vars *fractal */)
{
	if (ac == 1)
		display_mensg(0);
	else if (ac == 2 || ac == 4)
	{
		if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], \
		"Mandelbrot") == 0)
		{
			/* if (ac == 4 && is_number(av[2]) == 0 && is_number(av[3]) == 0)
				window_size(av, fractal);
			else if (ac == 4)
				display_mensg(2); */
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
	//return (0);
}