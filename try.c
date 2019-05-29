#include "fdf.h"

int	deal_key(int key, t_fun *f)
{
	if (key == 13)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x, f->y--, 0xFFFFFF);
	}
	if (key == 0)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x--, f->y, 0xFFFFFF);
	}
	if (key == 1)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x, f->y++, 0xFFFFFF);		
	}
	if (key == 2)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x++, f->y, 0xFFFFFF);		
	}
	if (key == 53)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		exit (1);
	}

	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
    printf("x = %d\ny = %d\n", x, y);
    return (0);
}

int main(void)
{
    int fd;
    char *line;
    char *new;
    t_fun *f;
    int x0;
    int y0;
    int k;

    printf("OK");
    f = (t_fun*)malloc(sizeof(t_fun));
    f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, 500, 500, "mlx 42");
    fd = open("text.txt", O_RDONLY);
    f->x = 20;
    f->y = 10;
    x0 = 10;
    y0 = 10;
    printf("OK");
    while (get_next_line(fd, &line) > 0)
    {
        new = line;
        while (*new)
        {
            if ((k = ft_atoi(new++)) == 0)
                //printf("%d ", k);
                ft_put_line(f->x, f->y, x0, y0, f);
            x0 += 10;
            f->x += 10;
            while (k > 9)
            {
                new++;
                k /= 10;
            }
            if (*new == ' ')
                new++;
        }
        printf("\n");
        y0 += 10;
        f->y += 10;
        f->x = 20;
        x0 = 10;
    }
    ft_put_line(250, 250, 220, 300, f);
    mlx_hook(f->win_ptr, 5, 10, mouse_release, f);
    mlx_hook(f->win_ptr, 2, 10, deal_key, f);
    mlx_loop(f->mlx_ptr);
    return (0);
}