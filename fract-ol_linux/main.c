/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/25 23:07:55 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	fractal;

	check_args(ac, av);
	init_mlx(ac, av, &fractal);
	run_fractal(&fractal);
	hook_events(&fractal);
	mlx_loop(fractal.mlx);
}
