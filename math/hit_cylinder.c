/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:08:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/15 09:20:48 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_intersect	check_cylinder_height(t_generic *cy, t_ray ray, t_intersect inter)
{
	const t_point	hit_point = ray.at(ray, inter.t);
	const double	projection = dot_product(vectors_res(hit_point, cy->center),
			cy->normal);

	if (projection > ((t_dimensions *)cy->dim)->height
		|| projection < 0)
		return (create_intersect(-1, NULL));
	return (inter);
}

t_intersect	check_cylinder_bottom(t_generic *cy, t_ray ray, t_intersect inter)
{
	const double	t_bottom = dot_product(vectors_res(cy->center,
				ray.origin), cy->normal) / dot_product(ray.dir, cy->normal);
	const double	radio = ((t_dimensions *)cy->dim)->diameter * 0.5;
	t_point			bottom_hit;

	if (t_bottom > 0)
	{
		bottom_hit = ray.at(ray, t_bottom);
		if (vector_length(vectors_res(bottom_hit, cy->center)) <= radio)
		{
			if (inter.t < 0 || t_bottom < inter.t)
				return (create_intersect(t_bottom, cy));
		}
	}
	return (inter);
}

t_intersect	check_cylinder_top(t_generic *cy, t_ray ray, t_intersect inter)
{
	const t_point	top_center = vectors_sum(cy->center,
			vector_multiply(cy->normal, ((t_dimensions *)cy->dim)->height));
	const double	t_top = dot_product(vectors_res(top_center, ray.origin),
			cy->normal) / dot_product(ray.dir, cy->normal);
	const double	radio = ((t_dimensions *)cy->dim)->diameter * 0.5;
	t_point			top_hit;

	if (t_top > 0)
	{
		top_hit = ray.at(ray, t_top);
		if (vector_length(vectors_res(top_hit, top_center)) <= radio)
		{
			if (inter.t < 0 || t_top < inter.t)
				return (create_intersect(t_top, cy));
		}
	}
	return (inter);
}

t_intersect	check_cylinder_parts(t_generic *cy, t_ray ray, t_intersect inter)
{
	inter = check_cylinder_height(cy, ray, inter);
	inter = check_cylinder_bottom(cy, ray, inter);
	inter = check_cylinder_top(cy, ray, inter);
	return (inter);
}

t_intersect	hit_cylinder(t_generic *cylinder, t_ray ray)
{
	const t_point	o_minus_c = vectors_res(ray.origin, cylinder->center);
	const double	radio = ((t_dimensions *)cylinder->dim)->diameter * 0.5;
	t_intersect		cylinder_intersect;
	double			var[6];

	cylinder_intersect = create_intersect(-1, NULL);
	var[0] = dot_product(ray.dir, ray.dir)
		- pow(dot_product(ray.dir, cylinder->normal), 2);
	var[1] = 2 * (dot_product(ray.dir, o_minus_c)
			- dot_product(ray.dir, cylinder->normal)
			* dot_product(o_minus_c, cylinder->normal));
	var[2] = dot_product(o_minus_c, o_minus_c)
		- pow(dot_product(o_minus_c, cylinder->normal), 2) - radio * radio;
	var[3] = var[1] * var[1] - 4 * var[0] * var[2];
	if (var[3] < 0)
		return (cylinder_intersect);
	var[4] = (-var[1] - sqrt(var[3])) / (2 * var[0]);
	var[5] = (-var[1] + sqrt(var[3])) / (2 * var[0]);
	if (var[4] > 0)
		cylinder_intersect = create_intersect(var[4], cylinder);
	else if (var[4] < 0 && var[5] > 0)
		cylinder_intersect = create_intersect(var[5], cylinder);
	return (check_cylinder_parts(cylinder, ray, cylinder_intersect));
}
