/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:49:34 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/16 09:33:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_cam(t_generic *cam, double angle_rad, int axis)
{
	t_camera	*cam_dim;

	cam_dim = (t_camera *)cam->dim;
	if (axis == X_AXIS)
	{
		cam_dim->orientation.x += angle_rad;
		if (cam_dim->orientation.x < 0)
			cam_dim->orientation.x += M_PI * 2;
		else if (cam_dim->orientation.x > M_PI * 2)
			cam_dim->orientation.x -= M_PI * 2;
	}
	else if (axis == Y_AXIS)
		cam_dim->orientation.y += angle_rad;
	else if (axis == Z_AXIS)
	{
		cam_dim->orientation.z += angle_rad;
		if (cam_dim->orientation.z < 0)
			cam_dim->orientation.z += M_PI;
		else if (cam_dim->orientation.z > M_PI)
			cam_dim->orientation.z -= M_PI;
	}
	cam_dim->right
		= sphere_point_polar(M_PI_2, cam_dim->orientation.x + M_PI_2);
}

void	translate_cam(t_generic *cam, t_point coord, int key)
{
	t_camera	*cam_dim;

	cam_dim = (t_camera *)cam->dim;
	if (key == UP)
		cam_dim->vp.vup = vectors_sum(cam_dim->vp.vup, coord);
	else if (key == RIGHT)
		cam_dim->vp.right = vectors_sum(cam_dim->vp.right, coord);
	else
		cam->center = vectors_sum(cam->center, coord);
}

static t_point	get_mousedelta(t_mouse mouse)
{
	t_point	mouse_delta;

	mouse_delta = vectors_res(mouse.position, mouse.buttonpress);
	return (mouse_delta);
}

void	cam_control(t_scene *scene, t_generic *element)
{
	t_point	mouse_delta;

	mouse_delta = (t_point){0};
	if (element != NULL && element->type == CAMERA)
	{
		mouse_delta = get_mousedelta(scene->mlx->mouse);
		if (scene->mlx->mouse.right == TRUE)
			update_element(
				scene,
				element,
				(double []){ROTATE, mouse_delta.x,
				mouse_delta.y, mouse_delta.z}
				);
	}
}
