/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:44:27 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/18 21:46:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx-linux/mlx.h"

# define MANDELBROT 1
# define JULIA 2

# define I_WIDTH 800
# define I_HEIGHT 800

# define ESC 65307
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define RIGHT_CLICK 2
# define LEFT_CLICK 1

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
	int	height_win;
	int	width_win;
	int	fractal;
	double	shift_x;
	double	shift_y;
	double	max_i;
	double	min_i;
	double	max_r;
	double	min_r;
	double	center_i;
	double	center_r;
	int	iter;
	int	height;
	int	width;
	unsigned int	count;
	int	r;
	int	g;
	int	b;
	int	t;
}				t_vars;

int	check_args(int ac, char **av, t_vars *vars);
void	choose_fractal(char **av, t_vars *vars);
int	run_fractal(t_vars *vars, t_data *img);

void	init_mlx(char **av, t_vars *vars, t_data *img);
int	hook_events(t_vars *vars);
void zoom_fractal(t_vars *fractal, int x, int y, double zoom);

void	set_mandel(t_data *img, t_vars *m);
void	set_julia(t_data *img, t_vars *j);
void julia_shift(t_vars *j, int x, int y);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	color_mandel(t_vars *m);
int	color_julia(t_vars *j);

int	is_number(char *str);

void	mlx_exit(t_vars *vars);

#endif
