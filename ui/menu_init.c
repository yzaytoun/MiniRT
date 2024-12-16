/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:26:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/14 19:51:35 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

t_control	*innit_bar(t_menu *menu, int pos_x, int pos_y,
	void (*change_fn)(t_control *data))
{
	t_pbar		*bar;
	t_control	*ctrl;

	ctrl = menu->controls.add(menu, 150, 15);
	ctrl->img = mnx_img_new(menu->mlx, 150, 15);
	ctrl->pos.x = pos_x;
	ctrl->pos.y = pos_y;
	ctrl->data = menu->data;
	bar = malloc(sizeof(t_pbar));
	ft_bzero(bar, sizeof(t_pbar));
	bar->progress = 50;
	bar->draw_eq = bar_value;
	bar->on_change = change_fn;
	ctrl->bar = bar;
	ctrl->dragable = 1;
	return (ctrl);
}

t_control	*innit_button(t_menu *menu, int pos_x, int pos_y,
	void (*on_click)(t_control *data))
{
	t_control	*ctrl;

	ctrl = menu->controls.add(menu, 60, 60);
	ctrl->img.ptr = NULL;
	ctrl->pos.x = pos_x;
	ctrl->pos.y = pos_y;
	ctrl->dim.x = ctrl->img.width;
	ctrl->dim.y = ctrl->img.height;
	ctrl->data = menu->data;
	ctrl->on_click = on_click;
	ctrl->dragable = FALSE;
	return (ctrl);
}

t_control	*innit_img_button(t_menu *menu, char *dir, t_point2D pos,
	void (*on_click)(t_control *data))
{
	t_control	*ctrl;

	ctrl = menu->controls.add(menu, 60, 60);
	ctrl->img = image_load(menu->mlx, dir);
	ctrl->pos.x = pos.x;
	ctrl->pos.y = pos.y;
	ctrl->dim.x = ctrl->img.width;
	ctrl->dim.y = ctrl->img.height;
	ctrl->data = menu->data;
	ctrl->on_click = on_click;
	ctrl->dragable = FALSE;
	return (ctrl);
}
