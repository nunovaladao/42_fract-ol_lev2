/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/12 15:49:38 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	
	
	check_args(ac, av, &vars);
	
	init_mlx(&vars, &img);
	//vars.scale = 1.0;
	
	set_mandel(&img, 1000);
	//do_rectangle(&vars, &img);
	
	hook_events(&vars);
	mlx_loop(vars.mlx);
}
