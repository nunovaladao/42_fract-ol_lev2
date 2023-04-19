/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:44:27 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/19 23:12:46 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx-linux/mlx.h"
#include <math.h>

# define MANDELBROT 1
# define JULIA 2

# define I_WIDTH 800
# define I_HEIGHT 800

# define C_I 0.20015
# define C_R -1.1

# define ESC 65307
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	t_data	img;
	int	fractal;
	double zoom;
	double	c_i;
	double	c_r;
	int x_arr;
	int y_arr;
	int	iter;
	int	height;
	int	width;
	unsigned int	count;
	int	r;
	int	g;
	int	b;
	int	t;
}				t_vars;

void	check_args(int ac, char **av/* , t_vars *vars */);
int	run_fractal(t_vars *vars, t_data *img);

void	init_mlx(char **av, t_vars *vars, t_data *img);
int	hook_events(t_vars *vars);

void init_mandel(t_vars *fractal);
void	set_mandel(t_data *img, t_vars *m);

void init_julia(t_vars *fractal);
void	set_julia(t_data *img, t_vars *j);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	color_mandel(t_vars *m);
int	color_julia(t_vars *j);

int	is_number(char *str);
double ft_atod(const char *str);

void	mlx_exit(t_vars *vars);

#endif
