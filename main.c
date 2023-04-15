/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/15 16:16:43 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_mandelbrot	m;
	t_julia	j;

	check_args(ac, av, &vars);

	init_mlx(av, &vars, &img);

    choose_fractal(av, &vars);
	run_fractal(&vars, &img, &m, &j);

	hook_events(&vars);
	mlx_loop(vars.mlx);
}
