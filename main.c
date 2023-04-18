/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/18 21:37:15 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	fractal;
	t_data	img;

	check_args(ac, av, &fractal);
	init_mlx(av, &fractal, &img);
	choose_fractal(av, &fractal);
	run_fractal(&fractal, &img);
	hook_events(&fractal);
	mlx_loop(fractal.mlx);
}
