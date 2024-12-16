/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_checker_sets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:32:05 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 17:32:53 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	bar_set_param(t_scene *scene, t_ckrparam *p, t_pbar *bar, int var)
{
	t_menu	*menu;

	if (var <= 1)
	{
		if (var == 0)
			p->xsize = (int)(((float)bar->progress * 50) / 100.0);
		else
			p->ysize = (int)(((float)bar->progress * 50) / 100.0);
		render(scene);
	}
	else if (var == 2 || var == 3)
	{
		if (var == 2)
			scene->target_color = &p->acolor;
		else
			scene->target_color = &p->bcolor;
		menu = scene->mnx.get(&scene->mnx, MENU_RGB);
		menu->visible = !menu->visible;
	}
	scene->mnx.draw(&scene->mnx);
}

void	bar_set_xsize(t_control *control)
{
	bar_get_var(control, 0);
}

void	bar_set_ysize(t_control *control)
{
	bar_get_var(control, 1);
}

void	bar_set_acolor(t_control *control)
{
	bar_get_var(control, 2);
}

void	bar_set_bcolor(t_control *control)
{
	bar_get_var(control, 3);
}
