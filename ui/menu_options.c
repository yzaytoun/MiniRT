/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:38:31 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/16 14:13:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	bar_set_bounces(t_control *control)
{
	t_pbar	*bar;
	t_scene	*scene;

	bar = control->bar;
	if (!bar)
		return ;
	scene = (t_scene *)control->data;
	scene->bounces = bar->progress / 10 + 1;
	render(scene);
}

void	bar_set_alight_color(t_control *control, t_bool r, t_bool g, t_bool b)
{
	t_pbar	*bar;
	t_scene	*scene;

	bar = control->bar;
	if (!bar)
		return ;
	scene = (t_scene *)control->data;
	if (r)
		scene->a_light->material.color.r = (int)((float)bar->progress * 255.0)
			/ 100.0;
	else if (g)
		scene->a_light->material.color.g = (int)((float)bar->progress * 255.0)
			/ 100.0;
	else if (b)
		scene->a_light->material.color.b = (int)((float)bar->progress * 255.0)
			/ 100.0;
	render(scene);
}

t_menu	*create_menu_options(t_scene *scene)
{
	t_menu		*menu;
	t_control	*ctrl;

	menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
	menu->data = scene;
	menu->background = mnx_img_new(scene->mlx->mlx, 200, 256);
	img_iter_context(&menu->background, &scene->menu_color, round_background);
	menu->pos = (t_point2D){(WIN_W - menu->background.width) * 0.5,
		(WIN_H - menu->background.height) * 0.5};
	ctrl = innit_bar(menu, 25, 32, bar_set_bounces);
	add_label(ctrl, ft_strdup("Bounces"), (t_point2D){0, -24}, WHITE);
	ctrl = innit_bar(menu, 25, 96, bar_set_alight_red);
	add_label(ctrl, ft_strdup("Ambient Red"), (t_point2D){0, -24}, WHITE);
	ctrl = innit_bar(menu, 25, 160, bar_set_alight_green);
	add_label(ctrl, ft_strdup("Ambient Green"), (t_point2D){0, -24}, WHITE);
	ctrl = innit_bar(menu, 25, 224, bar_set_alight_blue);
	add_label(ctrl, ft_strdup("Ambient Blue"), (t_point2D){0, -24}, WHITE);
	menu->visible = FALSE;
	return (menu);
}
