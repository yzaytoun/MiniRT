/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:49:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/04/08 20:29:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	*get_intersect_vars(
	t_generic *co, t_ray ray, t_dimensions *dim, double h_ratio)
{
	double	*v;
	t_point	oc;

	oc = vectors_res(ray.origin, co->center);
	v = malloc(sizeof(double) * 5);
	if (v != NULL)
	{
		v[0] = dot_product(ray.dir, ray.dir)
			- dot_product(ray.dir, co->normal)
			* dot_product(ray.dir, co->normal) * (1 + h_ratio);
		v[1] = dot_product(ray.dir, oc)
			- dot_product(oc, co->normal)
			* dot_product(ray.dir, co->normal)
			* (1 + h_ratio) + h_ratio * dim->height
			* dot_product(ray.dir, co->normal);
		v[2] = dot_product(oc, oc)
			- dot_product(oc, co->normal)
			* dot_product(oc, co->normal)
			* (1 + h_ratio) - (dim->diameter * 0.5) + 2 * h_ratio * dim->height
			* dot_product(oc, co->normal);
		v[3] = (v[1] * v[1]) - (v[0] * v[2]);
	}
	return (v);
}

static void	get_intersect(t_ray ray, double *v, t_point *inter, double *t)
{
	if (v[4] > 0)
	{
		*inter = ray.at(ray, v[4]);
		*t = v[4];
	}
	else if (v[4] < 0 && v[5] > 0)
	{
		*inter = ray.at(ray, v[5]);
		*t = v[5];
	}
}

static t_intersect	get_cone_intersect(
		t_generic *co, t_ray ray, t_dimensions *dim, double *v)
{
	t_intersect		result;
	t_point			inter;
	double			len;
	double			t;

	result = create_intersect(-1, NULL);
	inter = create_point(0, 0, 0);
	if (v == NULL)
		return (result);
	v[4] = (-v[1] - sqrt(v[3])) / v[0];
	v[5] = (-v[1] + sqrt(v[3])) / v[0];
	get_intersect(ray, v, &inter, &t);
	len = projection_length(co->normal, vectors_res(inter, co->center));
	free(v);
	if (len > 0 && len < dim->height)
		result = create_intersect(t, co);
	return (result);
}

t_intersect	hit_cone(t_generic *co, t_ray ray)
{
	t_dimensions	*dim;
	t_intersect		intersect_cone;
	double			h_ratio;

	dim = (t_dimensions *)co->dim;
	h_ratio = (dim->diameter * 0.5) / (pow(dim->height, 2));
	intersect_cone = get_cone_intersect(
			co,
			ray,
			dim,
			get_intersect_vars(co, ray, dim, h_ratio));
	return (intersect_cone);
}
