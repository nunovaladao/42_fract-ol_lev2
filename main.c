/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/14 10:17:35 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_mandelbrot m;
	
	check_args(ac, av, &vars);
	
	init_mlx(&vars, &img);
	//vars.scale = 1.0;
	
	set_mandel(&m, &img, &vars);
	//do_rectangle(&vars, &img);
	
	hook_events(&vars);
	mlx_loop(vars.mlx);
}
