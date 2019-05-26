/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:00:52 by ckatelin          #+#    #+#             */
/*   Updated: 2019/05/26 15:47:55 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int mouse_press(int button, int x, int y, t_fun *f)
{
	if (button == 1)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x++, f->y++, 0xFF00FF);
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

int circle(t_fun *f, int r, int x1, int y1)
{
	int x = 0;
   int y = r;
   int delta = 1 - 2 * r;
   int error = 0;
   while (y >= 0)
	{
       mlx_pixel_put(f->mlx_ptr, f->win_ptr, x1 + x, y1 + y, 0xFFFFFF);
       mlx_pixel_put(f->mlx_ptr, f->win_ptr, x1 + x, y1 - y, 0xFFFFFF);
       mlx_pixel_put(f->mlx_ptr, f->win_ptr, x1 - x, y1 + y, 0xFFFFFF);
       mlx_pixel_put(f->mlx_ptr, f->win_ptr, x1 - x, y1 - y, 0xFFFFFF);
       error = 2 * (delta + y) - 1;
       if ((delta < 0) && (error <= 0))
	   {
           delta += 2 * ++x + 1;
           continue;
	   }
       if ((delta > 0) && (error > 0))
	   {
           delta -= 2 * --y + 1;
           continue;
	   }
       delta += 2 * (++x - y--);
	}
	return (0);
}
int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int fd;
	char buf[1000];
	int i;
	int ret;
	int x;
	int y;
	t_fun *f;
	void *img;
	int chto;
	int kto;

	f = (t_fun*)malloc(sizeof(t_fun));
	f->x = 250;
	f->y = 250;
	x = 10;
	y = 10;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, 500, 500, "mlx 42");
/*	while ((ret = read(fd, buf, 38)) > 0)
	{
		y = 10;
		i = 0;
		buf[ret] = '\0';
		while (buf[i])
		{
			if (buf[i++] == '1')
			{
				mlx_pixel_put(f->mlx_ptr, f->win_ptr, y, x, 0xFFFFFF);
			}
			y++;
		}
		x++;
	}
	*/
//	kto = mlx_loop_hook(f->mlx_ptr, deal_key, f);	
//	chto = bresen(250, 450, 300, 350, f);
	//img = mlx_new_image(f->mlx_ptr, 50, 50);
	//mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, img, 300, 300);
	circle(f, 50, 250, 250);
	mlx_key_hook(f->win_ptr, deal_key, f);
	mlx_hook(f->win_ptr, 2, 10, deal_key, f);
	mlx_hook(f->win_ptr, 17, 100, mouse_press, f);
	/*
	mlx_new_image(f->mlx_ptr, 50, 50);
//	mlx_key_hook(f->win_ptr, deal_key, f);
*/
	mlx_loop(f->mlx_ptr);
	return (0);
}
