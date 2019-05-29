#include "fdf.h"

int ft_linelow(int x0, int y0, int x1, int y1, t_fun *f)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    int d;
    int y;
    int x;

    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    d = 2*dy - dx;
    y = y0;
    x = x0;
    
    while (x < x1)
    {
        mlx_pixel_put(f->mlx_ptr, f->win_ptr, x, y, 0xFF00FF);
        if (d > 0)
        {
            y = y + yi;
            d = d - 2*dx;
        }
        d = d + 2*dy;
        x++;
    }
    return (0);
}

int ft_linehigh(int x0, int y0, int x1, int y1, t_fun *f)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    int d;
    int y;
    int x;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    d = 2*dx - dy;
    y = y0;
    x = x0;
    
    while (y < y1)
    {
        mlx_pixel_put(f->mlx_ptr, f->win_ptr, x, y, 0xFF00FF);
        if (d > 0)
        {
            x = x + xi;
            d = d - 2*dy;
        }
        d = d + 2*dx;
        y++;
    }
    return(0);
}
 
int   ft_put_line(int x0, int y0, int x1, int y1, t_fun *f)
 {
  if (abs(y1 - y0) < abs(x1 - x0))
  {
    if (x0 > x1)
      ft_linelow(x1, y1, x0, y0, f);
    else
      ft_linelow(x0, y0, x1, y1, f);
  }
  else
  {
    if (y0 > y1)
      ft_linehigh(x1, y1, x0, y0, f);
    else
      ft_linehigh(x0, y0, x1, y1, f);
  }
  return (0);
 }