/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/22 20:47:29 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *str)
{
	double	res;
	int		s;
	int		i;
	double	nb;

	s = 1;
	res = 0;
	nb = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	while ((str[i] >= '0' && str[i] <= '9'))
	{
        if (str[i] == '.')
		    i++;
		res = res + (str[i++] - '0') * 0.1 * nb;
		nb = nb / 10;
	}
	return (res * s);
}

bool is_double(char *arg) 
{
    int tamanho = ft_strlen(arg);
    int i = 0;
    
    while (i < tamanho) 
    {
        char c = arg[i];
        if ((c < '0' || c > '9') && c != '.' && c != '-') {
            return false;
        }
        i++;
    }
    return true;
}

bool valid_size(char **av)
{
    double arg;
	static int i;
	
	i = 2;
	while (av[i])
	{
		arg = ft_atod(av[i]);
		if (arg >= -2.0 && arg <= 1.0)
		{
			i++;	
			return true;
		}
	}
	return false;
}

int	is_valid(char *arg)
{
	if (is_double(arg) == true)
		return (0);
	return (1);
}


int	run_fractal(t_vars *fractal, t_data *img)
{
	if (fractal->fractal == MANDELBROT)
		set_mandel(img, fractal);
	if (fractal->fractal == JULIA)
		set_julia(img, fractal);
	return (0);
}

void	mlx_exit(t_vars *vars)
{
	//mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
