#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "./minilibx_macos/mlx.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct    s_fun
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     x;
    int     y;
}                t_fun;

#endif