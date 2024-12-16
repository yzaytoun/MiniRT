/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:25:35 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 16:57:32 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	close_menu(t_control *control)
{
	t_scene	*scene;

	scene = (t_scene *)control->data;
	control->menu->visible = !control->menu->visible;
	scene->mnx.draw(&scene->mnx);
	mnx_img_to_img(&scene->mnx.img, &scene->mlx->img, (t_point2D){0, 0});
}

void	button_close_shape(t_mlximg *img, int x, int y)
{
	int			dist;
	const int	rad = 8;

	dist = INT_MIN;
	if (x < rad && y < rad)
		dist = distance((t_point){x, y, 0}, (t_point){rad, rad, 0});
	else if (x > img->width - rad && y < rad)
		dist = distance((t_point){x, y, 0},
				(t_point){img->width - rad, rad, 0});
	else if (x < rad && y > img->height - rad)
		dist = distance((t_point){x, y, 0},
				(t_point){rad, img->height - rad, 0});
	else if (x > img->width - rad && y > img->height - rad)
		dist = distance((t_point){x, y, 0},
				(t_point){img->width - rad, img->height - rad, 0});
	if (dist < rad)
		my_mlx_pixel_put(img, x, y, 0x990000);
	else
		my_mlx_pixel_put(img, x, y, 0xFF000000);
}

void	add_button_close(t_scene *scene, t_menu *menu, int pos_x, int pos_y)
{
	t_control	*ctrl;

	ctrl = innit_button(menu, pos_x, pos_y, close_menu);
	ctrl->img = mnx_img_new(scene->mlx->mlx, 16, 16);
	img_iter(&ctrl->img, button_close_shape);
}
