/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:44:27 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/26 18:30:57 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <stdbool.h>

# define MANDELBROT 1
# define JULIA 2

# define I_WIDTH 800
# define I_HEIGHT 800

# define C_I 0.27015
# define C_R -0.7

# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct	s_vars 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int	fractal;
	double zoom;
	double	c_i;
	double	c_r;
	int	iter;
	int	height;
	int	width;
	unsigned int	count;
	int	r;
	int	g;
	int	b;
	int	t;
}				t_vars;

void	check_args(int ac, char **av);

int	run_fractal(t_vars *vars);
void	init_mlx(int ac, char **av, t_vars *vars);
int	hook_events(t_vars *vars);

void init_mandel(t_vars *fractal);
void	set_mandel(t_vars *m);

void init_julia(int ac, char **av, t_vars *fractal);
void	set_julia(t_vars *j);

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	color_mandel(t_vars *m);
int	color_julia(t_vars *j);

double valid_size(char **av, char a);
bool is_double(char *arg);
double ft_atod(char *str);

void	mlx_exit(t_vars *vars);

#endif
