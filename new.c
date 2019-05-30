#include "fdf.h"

int main(void)
{
    t_fun *f;

    f = (t_fun *)malloc(sizeof(t_fun));
    f->mlx_ptr = mlx_init();
    f->win_ptr = mlx_new_window(f->mlx_ptr, 700, 700, "mlx 42");
    draw_line(f);
    mlx_hook(f->win_ptr, 2, 10, deal_key, f);
    mlx_loop(f->mlx_ptr);
    return (0);
}