/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:00:04 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/07 14:53:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

// Ese menu realmente sera para mostrar ayuda.
/* t_menu *create_menu_sidebar(t_scene *scene)
{
    t_menu *menu;

    menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
    menu->data = scene;
    innit_img_button(menu, "ui/img/LogoT.xpm", (t_point2D){0, 0}, toggle_rgb);
    menu->pos = (t_point2D){ WIN_W - 65, WIN_H - 65 };
    menu->visible = 1;
    return menu;
} */

void	round_background(t_mlximg *img, void *data, int x, int y)
{
	int			dist;
	const int	rad = 8;

	dist = INT_MIN;
	if (x < rad && y < rad)
		dist = distance((t_point){x, y, 0}, (t_point){rad, rad, 0});
	else if (x > img->width - rad && y < rad)
		dist = distance(
				(t_point){x, y, 0}, (t_point){img->width - rad, rad, 0});
	else if (x < rad && y > img->height - rad)
		dist = distance(
				(t_point){x, y, 0}, (t_point){rad, img->height - rad, 0});
	else if (x > img->width - rad && y > img->height - rad)
		dist = distance(
				(t_point){x, y, 0},
				(t_point){img->width - rad, img->height - rad, 0});
	if (dist < rad)
		my_mlx_pixel_put(img, x, y, color_int(*(t_color *)data));
	else
		my_mlx_pixel_put(img, x, y, 0xFF000000);
}

void	img_iter(t_mlximg *img, void (*f)(t_mlximg *img, int x, int y))
{
	int		x;
	int		y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			f(img, x, y);
	}
}

void	add_label(t_control *ctrl, char *text, t_point2D pos, int color)
{
	ctrl->label = malloc(sizeof(t_label));
	ctrl->label->text = text;
	ctrl->label->pos.x = ctrl->pos.x + pos.x;
	ctrl->label->pos.y = ctrl->pos.y + pos.y;
	ctrl->label->color = color;
}

//scene->mnx.add(&scene->mnx, create_menu_sidebar(scene)); No borrar
void	create_menus(t_scene *scene)
{
	scene->mnx = mnx_innit(scene->mlx->mlx, scene->mlx->win, WIN_W, WIN_H);
	scene->mnx.add(&scene->mnx, create_menu_upperbar(scene));
	scene->mnx.add(&scene->mnx, create_menu_material(scene));
	scene->mnx.add(&scene->mnx, create_menu_options(scene));
	scene->mnx.add(&scene->mnx, create_menu_checker(scene));
	scene->mnx.add(&scene->mnx, create_menu_rgb(scene));
}
