#include "fractol.h"

void do_rectangle(t_vars *vars, t_data *img)
{
    int y = 200;

    while (y <= 300)
    {
        y++;
        int x = 200;
        while (x <= 300)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
            x++;
        }
    }

    int a = 200;
    
    while (a <= 300)
    {
        a++;
        int b = 400;
        while (b <= 500)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, img->img, b, a);
            b++;
        }
    }
}