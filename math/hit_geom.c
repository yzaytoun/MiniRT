/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_geom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:13:10 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/25 16:06:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	get_geom_intersection(
	t_intersect *hit, t_ray ray, t_generic *geom, t_bool check_geom_bbox)
{
	if (check_geom_bbox
		&& check_hit_bbox(ray, geom->bbox)
		&& geom->hit && geom->type != PLANE)
		*hit = geom->hit(geom, ray);
	else if (!check_geom_bbox && geom->hit)
		*hit = geom->hit(geom, ray);
}

static t_intersect	get_intersection(
	t_list *objlist, t_ray ray, t_generic *origin, t_bool check_geom_bbox)
{
	t_intersect		front;
	t_list			*node;
	t_generic		*geom;
	t_intersect		hit;

	front = create_intersect(-1, NULL);
	if (objlist)
	{
		node = objlist;
		while (node)
		{
			hit.t = -1;
			geom = (t_generic *)node->content;
			if (geom && (!origin || (origin && origin->id != geom->id)))
				get_geom_intersection(&hit, ray, geom, check_geom_bbox);
			if (hit.t > T_MIN && (hit.t < front.t || front.t == -1))
				front = hit;
			node = node->next;
		}
		if (front.t > T_MIN)
			front.point = ray.at(ray, front.t);
	}
	return (front);
}

t_intersect	get_node_inter(t_scene *scene, t_ray ray, t_generic *origin)
{
	t_intersect	front;

	front = create_intersect(-1, NULL);
	while (scene->nav->currnode && front.t < T_MIN)
	{
		front = get_intersection(scene->nav->currnode->objlist, ray,
				origin, scene->check_geom_bbox);
		if (front.t < T_MIN)
			scene->nav->currnode
				= get_next_neighbour(scene->nav->currnode, ray);
	}
	return (front);
}

t_intersect	hit_geom(t_scene *scene,
	t_ray ray, t_generic *origin, t_bool update_lastnode)
{
	t_intersect	nodeinter;
	t_intersect	rootinter;

	if (!update_lastnode && scene->nav)
		scene->nav->moveto(&scene->nav, LAST_NODE);
	if (scene->use_octree && scene->nav && scene->nav->root)
	{
		rootinter = get_intersection(scene->nav->root->objlist,
				ray, origin, scene->check_geom_bbox);
		nodeinter = get_node_inter(scene, ray, origin);
		if ((rootinter.t > T_MIN
				&& nodeinter.t > T_MIN && rootinter.t < nodeinter.t)
			|| (rootinter.t > T_MIN && nodeinter.t < T_MIN))
			nodeinter = rootinter;
		if (update_lastnode && nodeinter.t > T_MIN)
			scene->nav->lastnode = scene->nav->root;
	}
	else
		nodeinter = get_intersection(
				scene->geometries, ray, origin, scene->check_geom_bbox);
	return (nodeinter);
}
