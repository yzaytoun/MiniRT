/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:31:49 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/25 12:04:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_vertices(t_bbox *bbox, t_point bbmax, t_point bbmin)
{
	bbox->vertices[0] = bbmin;
	bbox->vertices[1] = bbmax;
	bbox->vertices[2] = create_point(bbmax.x, bbmin.y, bbmin.z);
	bbox->vertices[3] = create_point(bbmax.x, bbmax.y, bbmin.z);
	bbox->vertices[4] = create_point(bbmin.x, bbmax.y, bbmin.z);
	bbox->vertices[5] = create_point(bbmin.x, bbmin.y, bbmax.z);
	bbox->vertices[6] = create_point(bbmin.x, bbmax.y, bbmax.z);
	bbox->vertices[7] = create_point(bbmax.x, bbmin.y, bbmax.z);
}

void	get_sphere_bbox(t_generic *generic)
{
	t_dimensions	*dim;

	dim = generic->dim;
	generic->bbox.bbmax
		= vectors_sum_escalar(generic->center, dim->diameter / 2);
	generic->bbox.bbmin
		= vectors_res_escalar(generic->center, dim->diameter / 2);
	set_vertices(&generic->bbox, generic->bbox.bbmax, generic->bbox.bbmin);
}

void	get_ciruclar_prism_bbox(t_generic *generic)
{
	t_dimensions	*dim;

	dim = generic->dim;
	if (dim->height > dim->diameter)
	{
		generic->bbox.bbmax = vectors_sum_escalar(generic->center, dim->height);
		generic->bbox.bbmin = generic->center;
	}
	else
	{
		generic->bbox.bbmax
			= vectors_sum_escalar(generic->center, dim->diameter / 2);
		generic->bbox.bbmin
			= vectors_res_escalar(generic->center, dim->diameter / 2);
	}
	set_vertices(&generic->bbox, generic->bbox.bbmax, generic->bbox.bbmin);
}

/*
	@returns TRUE if the bbox intersects with ray, else FALSE
*/
t_bool	check_hit_bbox(t_ray ray, t_bbox bbox)
{
	t_point	tenter;
	t_point	texit;
	double	tmax;
	double	tmin;

	texit.x = (bbox.bbmax.x - ray.origin.x) / ray.dir.x;
	tenter.x = (bbox.bbmin.x - ray.origin.x) / ray.dir.x;
	texit.y = (bbox.bbmax.y - ray.origin.y) / ray.dir.y;
	tenter.y = (bbox.bbmin.y - ray.origin.y) / ray.dir.y;
	texit.z = (bbox.bbmax.z - ray.origin.z) / ray.dir.z;
	tenter.z = (bbox.bbmin.z - ray.origin.z) / ray.dir.z;
	tmax = max((double []){
			texit.x, texit.y, texit.z, tenter.x, tenter.y, tenter.z}, 6);
	tmin = min((double []){
			texit.x, texit.y, texit.z, tenter.x, tenter.y, tenter.z}, 6);
	return (tmax > 0 && tmax >= tmin);
}
