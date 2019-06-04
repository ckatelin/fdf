#include "fdf.h"

int draw_map(int fd, char *line, t_fun *f)
{
    char *new;
    int x0;
    int y0;
    int k;
    int x1;
    int y1;
    t_put current;
    t_put start;
    t_put end;
    t_put delta;

    f->x = 20;
    f->y = 10;
    x0 = 10;
    y0 = 10;
    f->current = 0x00FF00;
    f->start = 0xFFFFFF;
    f->end = 0x000000;
    while (get_next_line(fd, &line) > 0)
    {
        new = line;
        while (*new)
        {
                if ((k = ft_atoi(new++)) == 0)
                {
//                    iso(&f->x, &f->y, 0);
                    ft_put_line(x0, y0, f->x, f->y, f, 0xFF00FF);
                }
                else
                {
                    start.x = x0;
                    start.y = y0;
                    end.x = f->x;
                    end.y = f->y + 10;
                    current.x = f->x;
                    current.y = f->y;
                    delta.x = abs(end.x - start.x);
                    delta.y = abs(end.y - start.y);
                    printf("color = %d\n", get_color(current, start, end, delta));
                    ft_put_line(x0, y0, f->x, f->y + 10, f, get_color(current, start, end, delta));
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