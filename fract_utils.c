/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/19 22:38:31 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double power_of_10(int exp) 
{
    double res = 1.0;
    while (exp > 0) {
        res *= 10.0;
        exp--;
    }
    while (exp < 0) {
        res /= 10.0;
        exp++;
    }
    return res;
}

double ft_atod(const char *str) 
{
    double s = 1;
    double res = 0;
    int i = 0;
    double n = 1;

    if (str[i] == '-' || str[i] == '+') 
	{
        if (str[i] == '-')
            s *= -1;
        i++;
    }
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
    while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
            res = res + (str[i++] - '0') * 0.1 * n;
			n = n / 10;
    }
    return ((res) * s);
}


int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
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
