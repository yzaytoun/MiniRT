/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/01 18:41:14 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// Se podría implementar una escala en el material.
t_point	normal_from_mat(t_generic *geom, t_point p, t_point n, t_material	mat)
{
	t_point	nmat;
	t_point	uv;
	t_point	v;
	t_point	u;

	uv = uv_at(p, geom, &u, &v);
	nmat = color_to_vector(color_at(mat.nmap, uv.x
				* mat.nmap.width, uv.y * mat.nmap.height));
	return (normalize(vectors_sum(
				vectors_sum(
					vector_multiply(u, nmat.x),
					vector_multiply(v, nmat.y)),
				vector_multiply(n, nmat.z))));
}

t_point	normal_at_sphere(t_generic *sphere, t_point p)
{
	t_material	mat;
	t_point		n;

	mat = sphere->material;
	n = normalize(vectors_res(p, sphere->center));
	if (!mat.nmap.ptr)
		return (n);
	return (normal_from_mat(sphere, p, n, mat));
}

t_point	normal_at_cylinder(t_generic *cy, t_point p)
{
	t_material	mat;
	t_point		res;
	t_point		n;

	mat = cy->material;
	res = vectors_res(p, cy->center);
	n = normalize(vectors_res(res,
				vector_multiply(cy->normal, dot_product(res, cy->normal))));
	if (!mat.nmap.ptr)
		return (n);
	return (normal_from_mat(cy, p, n, mat));
}

t_point	normal_at_cone(t_generic *cone, t_point p)
{
	const t_dimensions	dim = *(t_dimensions *)cone->dim;
	const t_material	mat = cone->material;
	t_point				n;

	n = normalize(create_point(2 * p.x, 2 * p.y, -2 * p.z
				* pow(tan(0.5 * dim.diameter / dim.height), 2)));
	if (!mat.nmap.ptr)
		return (n);
	return (normal_from_mat(cone, p, n, mat));
}

t_point	normal_at_plane(t_generic *plane, t_point p)
{
	t_material	mat;
	t_point		n;

	mat = plane->material;
	n = plane->normal;
	if (!mat.nmap.ptr)
		return (n);
	return (normal_from_mat(plane, p, n, mat));
}
