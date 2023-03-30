#include "fractol.h"

void do_rectangle(t_vars vars, t_data img)
{
    int x = 100;
    int y = 100;

    while (y < 200)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
		y++;
	}
    while (x < 200)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
		x++;
    }
    x = 200;
    y = 100;
    while (y < 200)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
		y++;
    }
    x = 100;
    while (x < 200)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
		x++;
    }
}