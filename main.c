/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/03/28 18:23:09 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Mouse here!\n");
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	close_win(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_vars	vars;
	t_data	img;
	int x = 100;
	int y = 200;
	int xw;
	int yz;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 580, "Fract-ol!");
	img.img = mlx_new_image(vars.mlx, 1000, 580);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	
	while (x < 200)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
		x++;
		while (y < 300)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
			y++;
		}
	}
	
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse, &vars);
	mlx_hook(vars.win, 17, 1L<<0, close_win, &vars);
	
	mlx_loop(vars.mlx);
}
