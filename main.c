#include "fdf.h"

int main(int argc, char **argv)
{
    t_fun *f;
    char *line;
    int fd;

    fd = open(argv[1], O_RDONLY);
    printf("fd = %d\n", fd);
    f = (t_fun *)malloc(sizeof(t_fun));
    f->mlx_ptr = mlx_init();
    f->win_ptr = mlx_new_window(f->mlx_ptr, 1700, 1000, "mlx 42");
    draw_map(fd, line, f);
    ft_go(f);
    mlx_hook(f->win_ptr, 2, 10, deal_key, f);
    mlx_loop(f->mlx_ptr);
    close(fd);
    return (0);
}