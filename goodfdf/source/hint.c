/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <ckatelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:33:07 by kcorie            #+#    #+#             */
/*   Updated: 2019/07/18 20:34:16 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			add_hint(t_mlx_var *mlx_var)
{
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20, 0x95EC00, "Control:");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 15, 0xE83A93,
	"Zoom: Scroll Up(+) Scrool Down(-)");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 30, 0xFF6B40,
	"Rotate: Mouse move(right, left button press)");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 45, 0x476DD5,
	"Move: 'z' button then right button mouse move");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 60, 0xED002F,
	"Change color: 1, 2, 3, 4, 5 button at the right panel");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 75, 0xA43DD4,
	"Change sensitivity rotate: Up(+), Down(-)");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 90, 0xF63E62,
	"Change sensitivity move: Up_end(+), Down_end(-)");
	mlx_string_put(mlx_var->io, mlx_var->window, mlx_var->screen.width / 20,
	mlx_var->screen.heigh / 20 + 105, 0x39E24D, "Turn off hint: 'h'");
}
