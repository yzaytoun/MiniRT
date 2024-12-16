/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:50:09 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 17:34:38 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	bar_set_color(t_control *control, t_bool r, t_bool g, t_bool b)
{
	t_pbar	*bar;
	t_scene	*scene;

	bar = control->bar;
	if (!bar)
		return ;
	scene = (t_scene *)control->data;
	if (!scene->selected)
		return ;
	if (r)
		scene->target_color->r = (int)((float)bar->progress * 255.0) / 100.0;
	else if (g)
		scene->target_color->g = (int)((float)bar->progress * 255.0) / 100.0;
	else if (b)
		scene->target_color->b = (int)((float)bar->progress * 255.0) / 100.0;
	render(scene);
}

void	bar_set_red(t_control *control)
{
	bar_set_color(control, TRUE, FALSE, FALSE);
}

void	bar_set_green(t_control *control)
{
	bar_set_color(control, FALSE, TRUE, FALSE);
}

void	bar_set_blue(t_control *control)
{
	bar_set_color(control, FALSE, FALSE, TRUE);
}

t_menu	*create_menu_rgb(t_scene *scene)
{
	t_menu		*menu;
	t_control	*ctrl;

	menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
	menu->data = scene;
	menu->background = mnx_img_new(scene->mlx->mlx, 200, 196);
	img_iter_context(&menu->background, &scene->menu_color, round_background);
	menu->pos = (t_point2D){(WIN_W - menu->background.width) * 0.5,
		(WIN_H - menu->background.height) * 0.5};
	ctrl = innit_bar(menu, 25, 32, bar_set_red);
	add_label(ctrl, ft_strdup("Material Red"), (t_point2D){0, -12}, WHITE);
	ctrl = innit_bar(menu, 25, 96, bar_set_green);
	add_label(ctrl, ft_strdup("Material Green"), (t_point2D){0, -12}, WHITE);
	ctrl = innit_bar(menu, 25, 160, bar_set_blue);
	add_label(ctrl, ft_strdup("Material Blue"), (t_point2D){0, -12}, WHITE);
	add_button_close(scene, menu, 184, 0);
	menu->visible = FALSE;
	return (menu);
}
