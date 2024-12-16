/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:50:09 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/07 14:54:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	bar_get_var(t_control *control, int var)
{
	t_scene		*scene;
	t_ckrparam	*p;

	scene = (t_scene *)control->data;
	if (!scene->selected || !scene->selected->material.params
		|| scene->selected->material.paramtype != CHECKER)
		return ;
	p = scene->selected->material.params;
	if (!p)
		return ;
	bar_set_param(scene, p, control->bar, var);
}

t_menu	*create_menu_checker(t_scene *scene)
{
	t_menu		*menu;
	t_control	*ctrl;

	menu = mnx_create_menu(scene->mlx->mlx, scene->mlx->win);
	menu->data = scene;
	menu->background = mnx_img_new(scene->mlx->mlx, 200, 196);
	img_iter_context(&menu->background, &scene->menu_color, round_background);
	menu->pos = (t_point2D){(WIN_W - menu->background.width) * 0.5,
		(WIN_H - menu->background.height) * 0.5};
	ctrl = innit_bar(menu, 25, 32, bar_set_xsize);
	add_label(ctrl, ft_strdup("Checker X Size"), (t_point2D){0, -12}, WHITE);
	ctrl = innit_bar(menu, 25, 96, bar_set_ysize);
	add_label(ctrl, ft_strdup("Checker Y Size"), (t_point2D){0, -12}, WHITE);
	ctrl = innit_button(menu, 25, 128, bar_set_acolor);
	add_label(ctrl, ft_strdup("Color A"), (t_point2D){32, 16}, WHITE);
	ctrl->img = mnx_img_new(scene->mlx->mlx, 24, 24);
	ctrl = innit_button(menu, 25, 160, bar_set_bcolor);
	add_label(ctrl, ft_strdup("Color B"), (t_point2D){32, 16}, WHITE);
	ctrl->img = mnx_img_new(scene->mlx->mlx, 24, 24);
	add_button_close(scene, menu, 184, 0);
	menu->visible = FALSE;
	return (menu);
}
