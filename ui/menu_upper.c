/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_upper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:34:47 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/14 20:13:54 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	toggle_opc(t_control *control)
{
	t_scene	*scene;
	t_pbar	*bar;
	t_menu	*opc;
	t_mnx	*mnx;

	scene = (t_scene *)control->data;
	mnx = &scene->mnx;
	opc = mnx->get(mnx, MENU_OPC);
	opc->visible = !opc->visible;
	bar = (t_pbar *)mnx_get_control(opc->controls.list, BAR_BOUNCES)->bar;
	bar->progress = scene->bounces * 10;
	bar = (t_pbar *)mnx_get_control(opc->controls.list, BAR_RED)->bar;
	bar->progress = scene->a_light->material.color.r * 100.0 / 255.0;
	bar = (t_pbar *)mnx_get_control(opc->controls.list, BAR_GREEN)->bar;
	bar->progress = scene->a_light->material.color.g * 100.0 / 255.0;
	bar = (t_pbar *)mnx_get_control(opc->controls.list, BAR_BLUE)->bar;
	bar->progress = scene->a_light->material.color.b * 100.0 / 255.0;
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win,
		scene->mlx->img.ptr, 0, 0);
	render(scene);
	scene->mnx.draw(&scene->mnx);
}

t_menu	*create_menu_upperbar(t_scene *scene)
{
	t_menu	*menu;

	menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
	menu->data = scene;
	innit_img_button(menu, "ui/img/Gear.xpm", (t_point2D){0, 0}, toggle_opc);
	menu->pos = (t_point2D){0, 0};
	menu->visible = 1;
	return (menu);
}
