/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:29:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 10:07:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	translate(t_scene *scene, t_generic *element, int key)
{
	const double	step = 2;

	if (element == NULL)
		return ;
	if (key == XK_q)
		update_element(
			scene, element, (double []){TRANSLATE, -step, 0, 0});
	else if (key == XK_e)
		update_element(
			scene, element, (double []){TRANSLATE, step, 0, 0});
	else if (key == XK_a)
		update_element(
			scene, element, (double []){TRANSLATE, 0, -step, 0});
	else if (key == XK_d)
		update_element(
			scene, element, (double []){TRANSLATE, 0, step, 0});
	else if (key == XK_w)
		update_element(
			scene, element, (double []){TRANSLATE, 0, 0, step});
	else if (key == XK_s)
		update_element(
			scene, element, (double []){TRANSLATE, 0, 0, -step});
}

void	modify_dim(t_scene *scene, t_generic *element, int key)
{
	if (element == NULL || element->dim == NULL)
		return ;
	if (key == XK_z)
	{
		if (element->type == CONE)
			update_dimensions(scene, element, (double []){MULTI, 2, 2, 1});
		else if (element->type == LIGHT || element->type == AMBIENT)
			update_dimensions(scene, element, (double []){SUM, 0.1});
		else
			update_dimensions(scene, element, (double []){MULTI, 2, 1, 1});
	}
	else if (key == XK_x)
	{
		if (element->type == CONE)
			update_dimensions(scene, element, (double []){DIVIDE, 2, 2, 1});
		else if (element->type == LIGHT || element->type == AMBIENT)
			update_dimensions(scene, element, (double []){SUB, 0.1});
		else
			update_dimensions(scene, element, (double []){DIVIDE, 2, 1, 1});
	}
}

void	rotate(t_scene *scene, t_generic *element, int key)
{
	if (element == NULL)
		return ;
	if (key == XK_Right || key == XK_KP_Left)
		update_element(scene, element, (double []){ROTATE, -ROT_ANGLE, X_AXIS});
	else if (key == XK_Left || key == XK_KP_Right)
		update_element(scene, element, (double []){ROTATE, ROT_ANGLE, X_AXIS});
	else if (key == XK_Down || key == XK_KP_Down)
		update_element(scene, element, (double []){ROTATE, -ROT_ANGLE, Y_AXIS});
	else if (key == XK_Up || key == XK_KP_Up)
		update_element(scene, element, (double []){ROTATE, ROT_ANGLE, Y_AXIS});
	else if (key == XK_KP_Home)
		update_element(scene, element, (double []){ROTATE, -ROT_ANGLE, Z_AXIS});
	else if (key == XK_KP_Prior)
		update_element(scene, element, (double []){ROTATE, ROT_ANGLE, Z_AXIS});
}

static void	menu_update(t_scene *scene)
{
	t_mnx	*mnx;

	mnx = &scene->mnx;
	((t_pbar *)mnx_get_control(
		mnx->get(mnx, MENU_RGB)->controls.list, 0)->bar)->progress
		= scene->selected->material.color.r * 100.0 / 255.0;
	((t_pbar *)mnx_get_control(
		mnx->get(mnx, MENU_RGB)->controls.list, 1)->bar)->progress
		= scene->selected->material.color.g * 100.0 / 255.0;
	((t_pbar *)mnx_get_control(
		mnx->get(mnx, MENU_RGB)->controls.list, 2)->bar)->progress
		= scene->selected->material.color.b * 100.0 / 255.0;
}

void	select_element(t_scene *scene, t_point point, t_elementtype type)
{
	int	x;
	int	y;

	if (point.x > WIN_W || point.y > WIN_H || point.x < 0 || point.y < 0)
		return ;
	x = (int)round(point.x);
	y = (int)round(point.y);
	if (type == DEFAULT)
		scene->selected = scene->geomatrix->matrix[y][x];
	else if (type == CAMERA)
		scene->selected
			= ft_lstget_index(scene->cameras, scene->selected_index);
	else if (type == LIGHT)
		scene->selected
			= ft_lstget_index(scene->d_lights, scene->selected_index);
	else if (type == AMBIENT)
		scene->selected = scene->a_light;
	if (scene->selected)
		menu_update(scene);
	if (scene->print_log)
		generic_log(scene->selected, FALSE);
}
