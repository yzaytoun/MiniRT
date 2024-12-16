/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:29:54 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 16:25:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

// Button Snap
/* void	button_snap(t_menu *menu, int x, int y)
{
	t_point2D	snap;

	if (!menu->buttons.count)
		return ;
	snap.x = (int)((x - menu->pos.x) / menu->snap.sep.x);
	snap.y = (int)((y - menu->pos.y) / menu->snap.sep.y);
	if (snap.x < 0)
		snap.x = 0;
	else if (snap.y < 1)
		snap.y = 1;
	else if (snap.x >= menu->snap.dim.x)
		snap.x = menu->snap.dim.x - 1;
	else if (snap.y >= menu->snap.dim.y)
		snap.y = menu->snap.dim.y;
	menu->button[menu->hover_on].pos.x = menu->snap.grid[snap.x][snap.y - 1].x;
	menu->button[menu->hover_on].pos.y = menu->snap.grid[snap.x][snap.y - 1].y;
	mnx_menu_clean(menu);
	mnx_menu_draw(menu);
} */

// Función mlx del loop del menú
void	mnx_hook_mousedown(int button, int x, int y, t_control *control)
{
	t_menu	*menu;

	if (!control)
		return ;
	menu = (t_menu *)control->menu;
	menu->selected = control;
	menu->mouse.x = x;
	menu->mouse.y = y;
	set_bit(&menu->events, button, 1);
	if (control->dragable)
		menu->events |= M_DRAGING;
}

// Función mlx del loop del menú
void	mnx_hook_mouseup(int button, t_control *control)
{
	t_menu	*menu;
	t_pbar	*bar;

	if (!control)
		return ;
	menu = (t_menu *)control->menu;
	set_bit(&menu->events, button, 0);
	set_bit(&menu->events, M_DRAG, 0);
	if (control->on_click)
		control->on_click(control);
	bar = (t_pbar *)control->bar;
	if (bar && bar->on_change)
		bar->on_change(control);
}
