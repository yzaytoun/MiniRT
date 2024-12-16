/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:18:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 18:10:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	hook_mousemove(int x, int y, t_scene *scene)
{
	if (check_mask_and(scene->mnx.events, M_DRAGING) && scene->mnx.hover_on)
		mnx_control_drag(scene->mnx.hover_on->menu, scene->mnx.hover_on, x, y);
	else if (x > 0 && y > 0 && x < WIN_W && y < WIN_H
		&& scene->mnx.matrix[x][y])
		scene->mnx.hover_on = scene->mnx.matrix[x][y];
	ft_lstiter(scene->mnx.mnx_lst, mnx_menu_draw);
	scene->mlx->mouse.position = create_point(x, y, 0);
	cam_control(scene, scene->selected);
	scene->mnx.draw(&scene->mnx);
	return (EXIT_SUCCESS);
}

int	hook_mousepress(int button, int x, int y, t_scene *scene)
{
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H && scene->mnx.matrix[x][y])
	{
		mnx_hook_mousedown(button, x, y, scene->mnx.matrix[x][y]);
		scene->mnx.events = scene->mnx.matrix[x][y]->menu->events;
	}
	scene->mlx->mouse.buttonpress = create_point(x, y, 0);
	if (button == M_WUP)
		select_element(scene, create_point(x, y, 0), AMBIENT);
	else if (button == M_RIGHT)
	{
		scene->mlx->mouse.right = TRUE;
		select_element(scene, create_point(x, y, 0), CAMERA);
	}
	else if (button == M_LEFT && !scene->mnx.matrix[x][y])
		select_element(scene, create_point(x, y, 0), DEFAULT);
	else if (button == M_DRAG)
		select_element(scene, create_point(x, y, 0), LIGHT);
	cam_control(scene, scene->selected);
	return (EXIT_SUCCESS);
}

int	hook_mouserelease(int button, int x, int y, t_scene *scene)
{
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H && scene->mnx.matrix[x][y])
		mnx_hook_mouseup(button, scene->mnx.matrix[x][y]);
	scene->mnx.events = 0;
	scene->mnx.hover_on = NULL;
	scene->mnx.draw(&scene->mnx);
	if (button == M_RIGHT)
	{
		scene->mlx->mouse.right = FALSE;
		scene->mlx->mouse.buttonrelease = create_point(x, y, 0);
	}
	return (EXIT_SUCCESS);
}
