/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:29:25 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 20:56:11 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	mix_ambiance(t_generic *light, t_color color)
{
	return (
		mix_color(color, light->material.color,
			((t_dimensions *)light->dim)->bright));
}

// Creo que esto lo tendremos que eliminar
/*
void	specular(t_scene *scene, t_ray ray, t_color *color)
{
	t_list		*node;
	t_generic	*light;
	t_color		lcolor;
	double		force;
	double		d;

	if (ray.from == NULL)
		return ;
	force = 0;
	lcolor = create_color(0, 0, 0);
	node = scene->d_lights;
	while (node)
	{
		light = (t_generic *)node->content;
		d = dot_product(normalize(ray.dir),
				normalize(vectors_res(light->center, ray.origin)));
		if (d > (1 - ray.from->material.rough - 0.01))
		{
			force = (d * d * ((t_dimensions *)light->dim)->bright + force) * 0.5;
			lcolor = sum_color(lcolor, mix_color(create_color(0, 0, 0),
						light->material.color,
						d * d * ((t_dimensions *)light->dim)->bright));
		}
		node = node->next;
	}
	if (force)
		*color = mix_color(*color, lcolor, 1);
}
*/
