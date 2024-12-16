/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:47:12 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/22 19:30:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

/*
	Transforma la imagen img a una imagen de Mapa de normales en data.
*/
void	bumb_to_normal(t_mlximg *img, void *data, int x, int y)
{
	t_color		c[9];
	t_point		p;
	t_mlximg	*dest;

	dest = (t_mlximg *)data;
	if (!x || !y || x >= WIN_W - 1 || y >= WIN_H - 1)
		return ;
	c[0] = color_at(*img, x - 1, y - 1);
	c[1] = color_at(*img, x, y - 1);
	c[2] = color_at(*img, x + 1, y - 1);
	c[3] = color_at(*img, x - 1, y);
	c[4] = color_at(*img, x, y);
	c[5] = color_at(*img, x + 1, y);
	c[6] = color_at(*img, x - 1, y + 1);
	c[7] = color_at(*img, x, y + 1);
	c[8] = color_at(*img, x + 1, y + 1);
	p.x = (c[2].r + 2 * c[5].r + c[8].r) - (c[0].r + 2 * c[3].r + c[6].r);
	p.y = (c[6].r + 2 * c[7].r + c[8].r) - (c[0].r + 2 * c[1].r + c[2].r);
	p.z = 42;
	p = vector_multiply(vectors_sum_escalar(normalize(p), 1), 0.5);
	my_mlx_pixel_put(dest, x, y, color_int(vector_to_color(p)));
}

void	set_img_mat(t_control *control)
{
	t_scene		*scene;
	t_material	*mat;

	scene = (t_scene *)control->data;
	if (!scene->selected)
		return ;
	mat = &scene->selected->material;
	if (mat->paramtype != IMAGE)
	{
		clear_material(mat, scene->mlx->mlx);
		mat->paramtype = IMAGE;
		mat->img = image_load(scene->mlx->mlx, "4753.xpm");
		render(scene);
	}
	scene->mnx.draw(&scene->mnx);
}

void	set_image_n(t_control *control)
{
	t_scene		*scene;
	t_material	*mat;

	scene = (t_scene *)control->data;
	if (!scene->selected)
		return ;
	mat = &scene->selected->material;
	if (!mat->nmap.ptr)
		mat->nmap = image_load(scene->mlx->mlx, "4753-normal.xpm");
	else
	{
		mlx_destroy_image(scene->mlx->mlx, mat->nmap.ptr);
		mat->nmap.ptr = NULL;
	}
	render(scene);
	scene->mnx.draw(&scene->mnx);
}

t_menu	*create_menu_material(t_scene *scene)
{
	t_menu	*menu;

	menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
	menu->data = scene;
	menu->background = mnx_img_new(scene->mlx->mlx, 290, 80);
	img_iter_context(&menu->background, &scene->menu_color, round_background);
	innit_img_button(menu, "ui/img/A.xpm", (t_point2D){10, 10}, set_checker);
	innit_img_button(menu, "ui/img/B.xpm", (t_point2D){80, 10}, set_img_mat);
	innit_img_button(menu, "ui/img/C.xpm", (t_point2D){150, 10}, set_image_n);
	innit_img_button(menu, "ui/img/D.xpm", (t_point2D){220, 10}, set_color);
	menu->pos = (t_point2D){(WIN_W - menu->background.width) * 0.5, WIN_H - 80};
	menu->visible = TRUE;
	return (menu);
}
