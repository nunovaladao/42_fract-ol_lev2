/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:16:00 by nuno              #+#    #+#             */
/*   Updated: 2023/04/27 11:38:06 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
			i++;
		res = res + (str[i++] - '0') * 0.1 * nb;
		nb = nb / 10;
	}
	return (res * s);
}

bool	is_double(char *arg)
{
	int		len;
	int		i;
	char	c;

	len = ft_strlen(arg);
	i = 0;
	while (i < len)
	{
		c = arg[i];
		if ((c < '0' || c > '9') && c != '.' && c != '-')
			return (false);
		i++;
	}
	return (true);
}

double	valid_size(char **av, char a)
{
	double	arg;
	int		i;

	i = 1;
	arg = 0.0;
	while (av[++i])
	{
		if ((a == 'x' && i == 2) || (a == 'y' && i == 3))
		{
			arg = ft_atod(av[i]);
			break ;
		}
	}
	if (arg >= -2.0 && arg <= 2.0)
		return (1);
	return (0);
}

int	run_fractal(t_vars *fractal)
{
	if (fractal->fractal == MANDELBROT)
		set_mandel(fractal);
	if (fractal->fractal == JULIA)
		set_julia(fractal);
	return (0);
}

void	mlx_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
