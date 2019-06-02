#include "fdf.h"

int draw_map(int fd, char *line, t_fun *f)
{
    char *new;
    int x0;
    int y0;
    int k;

    f->x = 20;
    f->y = 10;
    x0 = 10;
    y0 = 10;
    while (get_next_line(fd, &line) > 0)
    {
        new = line;
        while (*new)
        {
                if ((k = ft_atoi(new++)) == 0)
                {
                    ft_put_line(x0, y0, f->x, f->y, f);
                }
                else
                {
                    ft_put_line(x0, y0, f->x, f->y + 10, f);
                }
                x0 += 10;
                f->x += 10;
                while (k > 9)
                {
                    new++;
                    k /= 10;
                }
                while (*new == ' ')
                    new++;
        }
        y0 += 10;
        f->y += 10;
        f->x = 20;
        x0 = 10;
    }
    return (0);
}