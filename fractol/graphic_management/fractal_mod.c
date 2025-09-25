#include "fractals.h"

void    build_fractal_img(t_data *d, t_build *b)
{
    int     i;
    int     color;

    while (b->y < d->s.HI)
    {
        b->x = 0;
        while (b->x < d->s.WI)
        {
            compute_czxy(d, b, &i);
            while (check_limits(d, b, &i))
                if (!paint_x_axis(d, b, &i))
                    break ;
            if (i == d->f.m.mi)
                color = BLACK + 100;
            else
                color = d->s.color * d->s.zoom * i / d->s.disolvant;
            map_pixel(d, b, color);
            b->x += 1;
        }
        b->y += 1;
    }
}

void    print_image(t_data *d, int bdoor)
{
    (void)bdoor;
    mlx_clear_window(d->mlx, d->win);
    if (d->s.screen_mode == 0)
        mlx_string_put(d->mlx, d->win, 100, 100, RED, "VOUS ETES EN MODE ACCEUIL");
    else if (d->s.screen_mode == 1)
        mlx_put_image_to_window(d->mlx, d->win, d->f.m.img, 0, 0);
    else if (d->s.screen_mode == 2)
        mlx_put_image_to_window(d->mlx, d->win, d->f.j.img, 0, 0);
    else if (d->s.screen_mode == 3 || d->s.screen_mode == 4)
        mlx_put_image_to_window(d->mlx, d->win, d->f.n.img, 0, 0);
}

void    fractal_mod(t_data *d)
{
    t_build b;

    init_build(&b);
    if (d->s.screen_mode == 1)
    {
        replace_image(&d->f.m.img, d->mlx, d->s.WI, d->s.HI);
        d->f.m.a = mlx_get_data_addr(d->f.m.img, &d->f.m.b, &d->f.m.l, &d->f.m.e);
    }
    if (d->s.screen_mode == 2)
    {
        replace_image(&d->f.j.img, d->mlx, d->s.WI, d->s.HI);
        d->f.j.a = mlx_get_data_addr(d->f.j.img, &d->f.j.b, &d->f.j.l, &d->f.j.e);
    }
    if (d->s.screen_mode == 3 || d->s.screen_mode == 4)
    {
        replace_image(&d->f.n.img, d->mlx, d->s.WI, d->s.HI);
        d->f.n.a = mlx_get_data_addr(d->f.n.img, &d->f.n.b, &d->f.n.l, &d->f.n.e);
    }
    build_fractal_img(d, &b);
    print_image(d, 0);
}
