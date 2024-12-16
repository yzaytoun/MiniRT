/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:42:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/13 18:58:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_point	get_objmax(t_generic *generic)
{
	t_point	objmax;

	objmax = (t_point){0};
	if (generic)
	{
		if (generic->type == CAMERA)
			objmax = generic->center;
		else
		{
			objmax = generic->bbox.bbmax;
			if (vector_compare(generic->bbox.bbmin, objmax) == 1)
				objmax = generic->bbox.bbmin;
		}
	}
	return (objmax);
}

t_point	get_bbmax(t_list *lst)
{
	t_list		*node;
	t_point		max;
	t_point		objmax;

	max = (t_point){0};
	if (lst)
	{
		node = lst;
		while (node)
		{
			objmax = get_objmax((t_generic *)node->content);
			if (vector_compare(max, objmax) == 2)
				max = objmax;
			node = node->next;
		}
	}
	return (max);
}

/*
	@returns Octree with scene objects
*/
void	octree_init(t_scene *scene)
{
	t_octree	*root;
	t_point		geom_bbmax;
	t_point		cams_bbmax;

	if (scene == NULL)
		return ;
	root = create_octree(NULL, PARENT, NODE);
	geom_bbmax = get_bbmax(scene->geometries);
	cams_bbmax = get_bbmax(scene->cameras);
	if (vector_compare(cams_bbmax, geom_bbmax) == 1)
		geom_bbmax = cams_bbmax;
	octree_def_bbox(&root, vector_multiply(geom_bbmax, -1), geom_bbmax);
	octreesubdivide_node(&root);
	octreeinsert_geometry(root, scene->geometries);
	octreeinsert_cameras(root, scene->cameras);
	scene->nav = create_octreenav(root);
	octreeiter(root, octree_log);
}
