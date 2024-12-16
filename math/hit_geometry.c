/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_geometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:20:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/15 09:07:27 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_intersect	hit_sphere(t_generic *sphere, t_ray ray)
{
	const t_point	oc = vectors_res(ray.origin, sphere->center);
	t_intersect		sphere_intersect;
	double			var[6];

	sphere_intersect = create_intersect(-1, NULL);
	var[0] = dot_product(ray.dir, ray.dir);
	var[1] = dot_product(oc, ray.dir);
	var[2] = dot_product(oc, oc)
		- pow(((t_dimensions *)sphere->dim)->diameter * 0.5, 2.0);
	var[3] = var[1] * var[1] - var[0] * var[2];
	var[4] = (-var[1] - sqrt(var[3])) / var[0];
	var[5] = (-var[1] + sqrt(var[3])) / var[0];
	if (var[3] < 0)
		return (sphere_intersect);
	if (var[4] > 0)
		sphere_intersect = create_intersect(var[4], sphere);
	else if (var[4] < 0 && var[5] > 0)
		sphere_intersect = create_intersect(var[5], sphere);
	return (sphere_intersect);
}

t_intersect	hit_plane(t_generic *plane, t_ray ray)
{
	double	t;
	t_point	normal;

	normal = plane->normal;
	t = (dot_product(plane->normal,
				vectors_res(plane->center, ray.origin)))
		/ dot_product(normal, ray.dir);
	if (t <= 0)
		return (create_intersect(-1, NULL));
	return (create_intersect(t, plane));
}

t_intersect	create_intersect(double t, t_generic *geom)
{
	t_intersect	interection;

	interection.geom = geom;
	interection.t = t;
	return (interection);
}
