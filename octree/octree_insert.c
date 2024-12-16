/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:36:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/13 19:43:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	point_inside_node(t_point point, t_point bbmax, t_point bbmin)
{
	if (point.x >= bbmin.x && point.x < bbmax.x
		&& point.y >= bbmin.y && point.y < bbmax.y
		&& point.z >= bbmin.z && point.z < bbmax.z)
		return (TRUE);
	return (FALSE);
}

static void	check_geometry_bbox(t_octree **node, t_generic *generic)
{
	int	index;

	index = -1;
	while (++index < VERTICES_NUM)
	{
		if (point_inside_node(generic->bbox.vertices[index],
				(*node)->bbox.bbmax, (*node)->bbox.bbmin))
		{
			ft_lstinsert(&(*node)->objlist, generic, BACK);
			break ;
		}
	}
}

/*
	Inserts context into node object list
*/
void	octreeinsert(t_octree *node, void *context)
{
	t_generic	*generic;

	if (node == NULL || context == NULL)
		return ;
	generic = (t_generic *)context;
	if (node->nodeloc == PARENT && generic->type == PLANE)
		ft_lstinsert(&node->objlist, generic, BACK);
	else if (node->nodeloc != PARENT && generic->type != PLANE)
		check_geometry_bbox(&node, generic);
}
