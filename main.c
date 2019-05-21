/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:00:52 by ckatelin          #+#    #+#             */
/*   Updated: 2019/05/21 17:26:30 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
    #include <sys/types.h>
    #include <sys/uio.h>
    #include <unistd.h>
     #include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
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

	i = 0;
	fd = open("text.txt", O_RDONLY);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	while ((ret = read(fd, buf, 10)) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i])
		{
			if (buf[i++] == 1)
				mlx_pixel_put(mlx_ptr, win_ptr, i - 1, i - 1, 0x00FFFF);
		}
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
