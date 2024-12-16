/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:33:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/17 19:29:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_functionindex(t_elementtype type)
{
	int				i;
	const t_sdict	dict[5] = {
	{PLANE, (void *)(__UINTPTR_TYPE__)(1)},
	{SPHERE, (void *)(__UINTPTR_TYPE__)(2)},
	{CYLINDER, (void *)(__UINTPTR_TYPE__)(3)},
	{CONE, (void *)(__UINTPTR_TYPE__)(4)},
	{STATE_NULL, NULL}
	};

	(i = (__UINTPTR_TYPE__)get_sdict_value(dict, type));
	if (i == 0)
		return ((__UINTPTR_TYPE__)get_sdict_last(dict));
	else
		return (i - 1);
}

static void
	(*get_boundingbox(t_elementtype type))(t_generic *g)
{
	void	(*func[5])(t_generic *);

	func[0] = NULL;
	func[1] = get_sphere_bbox;
	func[2] = get_ciruclar_prism_bbox;
	func[3] = get_ciruclar_prism_bbox;
	func[4] = NULL;
	return (func[get_functionindex(type)]);
}

static t_intersect
	(*get_hitfunc(t_elementtype type))(t_generic *, t_ray)
{
t_intersect (*hit_func[5])(t_generic *, t_ray);

hit_func[0] = hit_plane;
hit_func[1] = hit_sphere;
hit_func[2] = hit_cylinder;
hit_func[3] = hit_cone;
hit_func[4] = NULL;
return (hit_func[get_functionindex(type)]);
}

static t_point
	(*get_normalfunc(t_elementtype type))(t_generic *, t_point)
{
t_point (*normalfunc[5])(t_generic *, t_point);

normalfunc[0] = normal_at_plane;
normalfunc[1] = normal_at_sphere;
normalfunc[2] = normal_at_cylinder;
normalfunc[3] = normal_at_cone;
normalfunc[4] = NULL;
return (normalfunc[get_functionindex(type)]);

}

t_generic	*new_element(t_elementtype type)
{
	t_generic	*generic;

	generic = ft_calloc(1, sizeof(t_generic));
	if (generic == NULL)
		return (NULL);
	generic->dim = NULL;
	generic->id = 0;
	generic->type = type;
	generic->hit = get_hitfunc(type);
	generic->normal_at = get_normalfunc(type);
	generic->get_bbox_boundaries = get_boundingbox(type);
	generic->material.nmap.ptr = NULL;
	generic->material.nmap.addr = NULL;
	generic->material.procedure = NULL;
	generic->material.params = NULL;
	generic->bbox = (t_bbox){0};
	return (generic);
}
