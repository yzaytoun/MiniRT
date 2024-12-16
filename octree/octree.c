/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree.c 	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:33:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/16 17:41:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
	Create and empty octree, object list is NULL and dimensions = {0}(t_point)
	@param nodetype: LEAF , NODE
	@param nodeloc: LUB, RUB, LDB, RDB, LUF, RUF, LDF, RDF, PARENT, CHILD
*/
t_octree	*create_octree(t_octree *parent, t_nloc nodeloc, t_ntype nodetype)
{
	t_octree	*octree;

	octree = malloc(sizeof(t_octree));
	if (octree == NULL)
		return (NULL);
	octree_setnodes_tonull(octree);
	octree->parent = parent;
	octree->center = (t_point){0};
	octree->nodeloc = nodeloc;
	octree->nodetype = nodetype;
	octree->objlist = NULL;
	octree->bbox = (t_bbox){0};
	return (octree);
}

/*
	Defines new bbox dimensions for root
*/
void	octree_def_bbox(t_octree **root, t_point min_point, t_point max_point)
{
	if (root == NULL || (*root) == NULL)
		return ;
	(*root)->bbox.bbmax = max_point;
	(*root)->bbox.bbmin = min_point;
	(*root)->center = mid_point(max_point, min_point);
}

void	destroy_octree(t_octree **root)
{
	int	index;

	if (root == NULL || (*root) == NULL)
		return ;
	ft_lstclear_nodes(&(*root)->objlist);
	index = -1;
	while (++index < CHILDS_NUM)
		destroy_octree(&(*root)->childnode[index]);
	free(*root);
}

/*
	Search get octree node that contains context
*/
t_octree	*octree_getnode(t_octree *root,
	t_octree *(*func)(t_octree *, void *), void *context)
{
	t_octree	*node;
	t_octree	*node_to_find;
	int			index;

	node = root;
	node_to_find = NULL;
	index = -1;
	while (++index < CHILDS_NUM && node_to_find == NULL)
	{
		if (node->childnode[index]
			&& node->childnode[index]->nodetype == NODE)
			node_to_find = octree_getnode(
					node->childnode[index], func, context);
		else
			node_to_find = func(node->childnode[index], context);
	}
	if (!node_to_find)
		node_to_find = func(root, context);
	return (node_to_find);
}
