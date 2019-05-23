# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:14:17 by ckatelin          #+#    #+#              #
#    Updated: 2019/05/23 20:31:57 by ckatelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g -I fdf.h main.c -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit