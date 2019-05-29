#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "./minilibx_macos/mlx.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct    s_fun
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     x;
    int     y;
}                t_fun;

int   ft_put_line(int x0, int y0, int x1, int y1, t_fun *f);
int ft_linehigh(int x0, int y0, int x1, int y1, t_fun *f);
int ft_linelow(int x0, int y0, int x1, int y1, t_fun *f);
//GNL
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_file
{
	char			*tail;
	int				file;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif