/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/10 16:52:30 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_mandelbrot mandel;
	
	check_args(ac, av, &vars);
	
	init_mlx(&vars);
	init_window(&vars, &img);
	vars.scale = 1.0;
	
	draw_mandelbrot(&mandel, &vars, &img);
	
	hook_events(&vars);
	mlx_loop(vars.mlx);
}
