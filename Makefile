# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:14:17 by ckatelin          #+#    #+#              #
#    Updated: 2019/06/04 18:26:37 by ckatelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ./srcs/libft/
NAME = fdf
GNL = ./srcs/gnl/get_next_line.c



all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -g -I fdf.h line.c draw.c main.c transorming.c color.c draw_map.c $(GNL) -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L $(LIB) -lft 

clean:
	make clean -C $(LIB)

fclean: clean
	make fclean -C $(LIB)

re: fclean all