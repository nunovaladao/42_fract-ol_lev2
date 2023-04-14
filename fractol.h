/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:44:27 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/14 22:52:43 by nuno             ###   ########.fr       */
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

typedef struct	s_julia
{
	double zoom;
	double max_i;
	double min_i;
	double max_r;
	double min_r;
	int	iter;
	int height;
	int width;
	unsigned int count;
	int r;
	int g;
	int b;
	int t;
}				t_julia;

typedef struct	s_mandelbrot
{
	double zoom;
	double max_i;
	double min_i;
	double max_r;
	double min_r;
	int	iter;
	int height;
	int width;
	unsigned int count;
	int r;
	int g;
	int b;
	int t;
}				t_mandelbrot;

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
	t_data auxil;
	t_data img;
	t_mandelbrot m;
	t_julia j;
	double scale;
	int height_win;
	int width_win;
	int fractal;
}				t_vars;

t_vars init(void);
int check_args(int ac, char **av, t_vars *vars/* , t_data *img, t_mandelbrot *m, t_julia *j */);
void choose_fractal(char **av, t_vars *vars);
int run_fractal(t_vars *vars, t_data *img, t_mandelbrot *m, t_julia *j);

void init_mlx(char **av, t_vars *vars, t_data *img);
int hook_events(t_vars *vars);

void set_mandel(t_mandelbrot *m, t_data *img, t_vars *vars);
void set_julia(t_julia *j, t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int color(t_mandelbrot *m);

void mlx_exit(t_vars *vars);

#endif
