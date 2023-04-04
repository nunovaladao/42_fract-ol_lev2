/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/04 23:40:10 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	
	check_args(ac, av);
	init_mlx(&vars);
	init_window(&vars, &img);
	vars.scale = 1.0;
	
	do_rectangle(&vars, &img);
	hook_events(&vars);
	mlx_loop(vars.mlx);
}
