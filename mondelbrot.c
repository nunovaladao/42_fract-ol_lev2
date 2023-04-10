
#define WIDTH 800
#define HEIGHT 600

typedef struct	s_complex
{
  double		r;
  double		i;
}				t_complex;

typedef struct	s_mandelbrot
{
  t_complex	min;
  t_complex	max;
  t_complex	factor;
  int			max_iter;
}				t_mandelbrot;

int	mandelbrot_iteration(t_complex c, int max_iter)
{
  t_complex	z;
  double	temp;
  int		iter;

  z.r = 0;
  z.i = 0;
  iter = 0;
  while (z.r * z.r + z.i * z.i <= 4 && iter < max_iter)
  {
    temp = z.r * z.r - z.i * z.i + c.r;
    z.i = 2 * z.r * z.i + c.i;
    z.r = temp;
    iter++;
  }
  return (iter);
}

void	draw_mandelbrot(t_mandelbrot *m, void *win_ptr, void *mlx_ptr)
{
  int		x;
  int		y;
  int		iter;
  int		color;

  y = 0;
  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH)
    {
      iter = mandelbrot_iteration((t_complex){m->min.r + x * m->factor.r,
      							m->min.i + y * m->factor.i}, m->max_iter);
      if (iter == m->max_iter)
        color = 0;
      else
        color = iter * 255 / m->max_iter;
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, color * 65536 + color * 256 + color);
      x++;
    }
    y++;
  }
}
