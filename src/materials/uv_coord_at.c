/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_coord_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:44:47 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 19:05:19 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point	uv_at(t_point p, t_generic *geom, t_point *u, t_point *v)
{
	t_point	c;

	if (geom->type == PLANE)
		c = uv_at_plane(geom, p, u, v);
	else if (geom->type == SPHERE)
		c = uv_at_sphere(geom, p, u, v);
	else if (geom->type == CYLINDER)
		c = uv_at_cylinder(geom, p, u, v);
	else if (geom->type == CONE)
		c = uv_at_cone(geom, p, u, v);
	else
		c = create_point(0, 0, 0);
	return (c);
}

t_point	uv_at_plane(t_generic *geom, t_point at, t_point *u, t_point *v)
{
	t_point			dot;
	const t_point	res = vectors_res(at, geom->center);
	const t_point	n = geom->normal;
	const t_point	c = geom->center;

	if (n.x > 0.1)
		*v = normalize(create_point(n.y / n.x + c.x, c.y + 1, c.z));
	else if (n.y > 0.1)
		*v = normalize(create_point(c.x + 1, n.x / n.y + c.y, c.z));
	else
		*v = normalize(create_point(c.x + 1, n.x / n.z + c.z, c.z));
	*u = normalize(cross_product(*v, geom->normal));
	dot.x = fabs(dot_product(res, *v)) * 0.06;
	dot.y = fabs(dot_product(res, *u)) * 0.06;
	return (create_point(dot.x - (int)dot.x, dot.y - (int)dot.y, 0));
}

t_point	uv_at_sphere(t_generic *geom, t_point at, t_point *u, t_point *v)
{
	t_point			uv;
	const t_point	res = vectors_res(at, geom->center);
	t_dimensions	*dim;

	dim = (t_dimensions *)geom->dim;
	*u = normalize(cross_product(create_point(0, 0, 1), res));
	*v = normalize(cross_product(*u, res));
	uv.x = atan(res.y / res.x) / (M_PI) + 0.5;
	uv.y = acos(res.z / (dim->diameter * 0.5)) / (M_PI);
	return (uv);
}

t_point	uv_at_cylinder(t_generic *geom, t_point at, t_point *u, t_point *v)
{
	t_point			uv;
	const t_point	res = vectors_res(at, geom->center);
	const t_point	n = normalize(vectors_res(res, vector_multiply(
					geom->normal, dot_product(res, geom->normal))));
	t_point			projection;
	double			dot;

	dot = dot_product(res, geom->normal);
	projection = vectors_res(res, vector_multiply(geom->normal, dot));
	*v = normalize(cross_product(geom->normal, n));
	*u = geom->normal;
	uv.x = atan(projection.y / projection.x) / (M_PI) + 0.5;
	dot *= 0.06;
	if (dot < 0)
		dot += 1;
	uv.y = fabs(dot - (int)dot);
	return (uv);
}

t_point	uv_at_cone(t_generic *geom, t_point at, t_point *u, t_point *v)
{
	t_point			uv;
	const t_point	res = vectors_res(at, geom->center);
	const t_point	n = normalize(create_point(2 * at.x, 2 * at.y, -2 * at.z
				* pow(tan(0.5 * ((t_dimensions *)geom->dim)->diameter
						/ ((t_dimensions *)geom->dim)->height), 2)));
	const double	dist = distance(vectors_sum(geom->center,
				vector_multiply(geom->normal,
					((t_dimensions *)geom->dim)->height)), at) * 0.1;
	const t_point	projection = vectors_res(res, vector_multiply(
				geom->normal, dot_product(res, geom->normal)));

	*u = normalize(cross_product(geom->normal, n));
	*v = normalize(cross_product(*u, n));
	uv.x = atan(projection.y / projection.x) / (M_PI) + 0.5;
	uv.y = dist - (int)dist;
	return (uv);
}
