/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/14 21:02:48 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_multiply(t_color color, double val)
{
	t_color	c;

	if (val < 0)
		return (color);
	c.r = (int)(color.r * val) & 255;
	c.g = (int)(color.g * val) & 255;
	c.b = (int)(color.b * val) & 255;
	return (c);
}

t_bool	is_light_visible(t_scene *scene, t_ray ray, t_generic *geom, double len)
{
	t_intersect	front;

	front = hit_geom(scene, ray, geom, FALSE);
	if (front.t == -1 || front.t > len)
		return (TRUE);
	return (FALSE);
}

void	iter_lights(void *content, void *data)
{
	const t_generic	*l = (t_generic *)content;
	t_ray			ray;
	t_scene			*s;
	t_point			raydir;
	t_point			aux;

	s = (t_scene *)data;
	raydir = vectors_res(l->center, s->calcs.front.point);
	aux.x = vector_length(raydir);
	ray = create_ray(s->calcs.front.point, vector_multiply(raydir, 1
				/ aux.x), s->calcs.front.geom);
	aux.y = dot_product(s->calcs.front.geom->normal_at(
				s->calcs.front.geom, s->calcs.front.point), ray.dir);
	if (aux.y > 0)
	{
		if (is_light_visible(s, ray, s->calcs.front.geom, aux.x))
		{
			s->calcs.lcolor = sum_color(s->calcs.lcolor, color_multiply(
						l->material.color, (1 - (s->calcs.front.geom)
							->material.rough) * ((t_dimensions *)l->dim)->bright
						* pow(aux.y, 12)));
			s->calcs.lcolor = sum_color(s->calcs.lcolor,
					color_multiply(l->material.color, aux.y));
		}
	}
}

t_color	hit_light(t_scene *scene)
{
	double	alpha;

	scene->calcs.lcolor = color_multiply(scene->a_light->material.color,
			((t_dimensions *)scene->a_light->dim)->bright * 0.5);
	alpha = color_alpha(scene->calcs.lcolor);
	ft_lstiter_context(scene->d_lights, iter_lights, scene);
	return (mix_color(mix_color(create_color(0, 0, 0), material_color(
					scene->calcs.front), alpha), scene->calcs.lcolor, alpha));
}
