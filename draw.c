#include "fdf.h"

int	deal_key(int key, t_fun *f)
{
	if (key == 53)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		exit (0);
	}
	return (0);
}

int mouse_release(int button, int x, int y, t_fun *k)
{
	if (button == 1)
	{
		k->x1 = x;
        k->y1 = y;
	}
    if (button == 2)
	{      
		k->x2 = x;
        k->y2 = y;
        draw_line(k);
	}
/*    else
    {
        exit (0);
    }
*/    
	return (0);
}

int draw_line(t_fun *k)
{
//	mlx_hook(k->win_ptr, 5, 10, mouse_release, k);    
//    mlx_hook(k->win_ptr, 5, 10, mouse_release, k);
    ft_put_line(k->x1, k->y1, k->x2, k->y2, k);
//    mlx_loop(k->mlx_ptr);
    return (0);
}


int ft_go(t_fun *k)
{
	mlx_hook(k->win_ptr, 4, 10, mouse_release, k);
	mlx_hook(k->win_ptr, 2, 10, deal_key, k);
	mlx_loop(k->mlx_ptr);
    return (0);
}