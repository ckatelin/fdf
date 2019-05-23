/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:00:52 by ckatelin          #+#    #+#             */
/*   Updated: 2019/05/23 20:33:16 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, t_fun *f)
{
	if (key == 12)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->y++, f->x, 0xFFFFFF);
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

	f = (t_fun*)malloc(sizeof(t_fun));
	f->x = 255;
	printf("OK1\n");
	f->y = 255;
	printf("OK1\n");
	x = 10;
	y = 10;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n", fd);
//	f->mlx_ptr = malloc(sizeof(void *) * 3);
	f->mlx_ptr = mlx_init();
	printf("OK1\n");
//	f->win_ptr = malloc(sizeof(void *) * 1000);
	f->win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	printf("OK1\n");
	while ((ret = read(fd, buf, 38)) > 0)
	{
		printf("ret = %d\n", ret);
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
	printf("end\n");

//	mlx_pixel_put(mlx_ptr, win_ptr, 100, 255, 0x00FFFF);
//	mlx_pixel_put(mlx_ptr, win_ptr, 100, 200, 0x00FFFF);
	mlx_key_hook(f->win_ptr, deal_key, &f);
	mlx_loop(f->mlx_ptr);
//	printf("end\n");
	return (0);
}
