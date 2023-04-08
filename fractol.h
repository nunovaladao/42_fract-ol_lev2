/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:44:27 by nsoares-          #+#    #+#             */
/*   Updated: 2023/04/09 00:16:50 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx-linux/mlx.h"
# include <math.h>

# define I_WIDTH 600
# define I_HEIGHT 600

# define ESC 65307
# define SCROLL_UP 5
# define SCROLL_DOWN 4

// Inicializar a janela;
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Events;
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data auxil;
	t_data img;
	double scale;
	int height_win;
	int width_win;
}				t_vars;

void do_rectangle(t_vars *vars, t_data *img);
void init_mlx(t_vars *vars);
void init_window(t_vars *vars, t_data *img);
int hook_events(t_vars *vars);
int check_args(int ac, char **av, t_vars *vars);

#endif
