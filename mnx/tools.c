/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:28:48 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/22 18:36:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

void	matrix_clear(t_control ***matrix, int win_width, int win_height)
{
	t_point2D	p;

	p.x = -1;
	while (++p.x < win_width)
	{
		p.y = -1;
		while (++p.y < win_height)
			matrix[p.x][p.y] = NULL;
	}
}

// Creates a new image for mlx library.
t_mlximg	mnx_img_new(void *mlx, int width, int height)
{
	t_mlximg	img;

	img.ptr = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

// Establece la mlx y la ventana que usará el menú y setea el resto a 0
t_menu	*mnx_create_menu(void *mlx, void *win)
{
	t_menu	*menu;

	menu = malloc(sizeof(t_menu));
	ft_bzero(menu, sizeof(t_menu));
	menu->mlx = mlx;
	menu->win = win;
	menu->controls.add = mnx_control_create;
	menu->controls.del = mnx_control_delete;
	return (menu);
}
