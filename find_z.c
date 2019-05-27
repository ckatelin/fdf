/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:20:08 by ckatelin          #+#    #+#             */
/*   Updated: 2019/05/27 18:50:42 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int bresen(int x0, int x1, int y0, int y1, t_fun *f)
{
     int deltax = abs(x1 - x0);
     int deltay = abs(y1 - y0);
     int error = 0;
     int deltaerr = deltay;
     int y = y0;
     int diry = y1 - y0;
	 int x;

     if (diry > 0 )
         diry = 1;
     if (diry < 0 )
         diry = -1;
	x = x0;
    while (x < x1)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, x, y, 0xFFFFFF);
         error = error + deltaerr;
         if (2 * error >= deltax)
		 {
             y = y + diry;
             error = error - deltax;
		 }
		 x++;
	}
	return (0);
}
int try(int x0, int x1, int y0, int y1, t_fun *f)
{
    while (y1 < y0)
    {
        mlx_pixel_put(f->mlx_ptr, f->win_ptr, x0, y1++, 0xFFFFFF);
    }
    return (0);
}

int main(void)
{
    int fd;
    char *line;
    int i;
    char *new;
    int k;
    t_fun *f;
    int x0;
    int y0;
    int check;

    check = 0;
    f = (t_fun*)malloc(sizeof(t_fun));
    f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, 500, 500, "mlx 42");
    mlx_hook(f->win_ptr, 2, 10, deal_key, f);
    f->x = 20;
    f->y = 10;
    x0 = 10;
    y0 = 10;
    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        new = line;
        while (*new)
        {
                printf("%d", k = ft_atoi(new++));
                if (k == 0)
                {
                    bresen(x0, f->x, y0, f->y, f);
                    if (check)
                        try(x0, f->x + 10, y0, f->y - 10, f);
                }
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
        y0 += 10;
        f->y += 10;
        f->x = 20;
        x0 = 10;
        check= 1;
//        printf("\n");
    }
    printf("i = %d", i);
    close(fd);
    try(250, 250, 300, 350,f);
    mlx_loop(f->mlx_ptr);
    return (0);
}