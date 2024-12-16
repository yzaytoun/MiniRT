/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:59:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 10:17:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
	@param vars
	vars[0] = KEY, vars[1 ... n] = values
	@note EX -> (double []){ROTATE, 30, X_AXIS}	
*/
void	update_element(t_scene *scene, t_generic *element, double vars[])
{
	if (vars[0] == ROTATE)
	{
		if (element->type == CAMERA)
			rotate_cam(element, to_radian(vars[1]), vars[2]);
		else
			rotate_vector(&element->normal, to_radian(vars[1]), vars[2]);
	}
	else if (vars[0] == TRANSLATE)
	{
		if (element->type == CAMERA)
			translate_cam(element,
				create_point(vars[1], vars[2], vars[3]), vars[4]);
		else
			element->center
				= vectors_sum(
					element->center, create_point(vars[1], vars[2], vars[3]));
	}
	if (is_geometry(element->type))
		reallocate_element(scene, element);
	render(scene);
}

void	update_dimensions(t_scene *scene, t_generic *element, double vars[])
{
	t_dimensions	*dim;

	dim = (t_dimensions *)element->dim;
	if (vars[0] == MULTI)
	{
		dim->diameter *= vars[1];
		dim->height *= vars[2];
		dim->ratio *= vars[3];
	}
	else if (vars[0] == DIVIDE)
	{
		dim->diameter /= vars[1];
		dim->height /= vars[2];
		dim->ratio /= vars[3];
	}
	else if (vars[0] == SUM)
		dim->bright += vars[1];
	else if (vars[0] == SUB && dim->bright > 0.1)
		dim->bright -= vars[1];
	if (element->get_bbox_boundaries)
		element->get_bbox_boundaries(element);
	if (is_geometry(element->type))
		reallocate_element(scene, element);
	render(scene);
}

void	update_material(t_scene *scene, t_generic *element, int key)
{
	if (!element || (is_geometry(element->type) == FALSE))
		return ;
	if (key == XK_v && element->material.rough < 1)
	{
		element->material.rough += 0.1;
		render(scene);
	}
	else if (key == XK_b && element->material.rough > 0)
	{
		element->material.rough -= 0.1;
		render(scene);
	}
}
