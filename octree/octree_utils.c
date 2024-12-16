/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:13:57 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/25 12:58:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
	Puts pointer to null without calling free()
*/
void	octree_setnodes_tonull(t_octree *root)
{
	int	index;

	if (root == NULL)
		return ;
	index = -1;
	while (++index < CHILDS_NUM)
		root->childnode[index] = NULL;
	index = -1;
	while (++index < NEIGHBOURS_NUM)
		root->neighbour[index] = NULL;
}

static void	get_bbox_dimenesions(
	t_octree *root, t_nloc childnode_loc, t_point *bbmax, t_point *bbmin)
{
	const t_point	maxp = root->bbox.bbmax;
	const t_point	minp = root->bbox.bbmin;
	const t_point	mid = root->center;
	const t_point	loc_matrix[CHILDS_NUM][2] = {
	{(t_point){mid.x, maxp.y, maxp.z}, (t_point){minp.x, mid.y, mid.z}}, //LUB
	{(t_point){maxp.x, maxp.y, maxp.z}, (t_point){mid.x, mid.y, mid.z}}, //RUB
	{(t_point){mid.x, maxp.y, mid.z}, (t_point){minp.x, mid.y, minp.z}}, //LDB
	{(t_point){maxp.x, maxp.y, mid.z}, (t_point){mid.x, mid.y, minp.z}}, //RDB
	{(t_point){mid.x, mid.y, maxp.z}, (t_point){minp.x, minp.y, mid.z}}, //LUF
	{(t_point){maxp.x, mid.y, maxp.z}, (t_point){mid.x, minp.y, mid.z}}, //RUF
	{(t_point){mid.x, mid.y, mid.z}, (t_point){minp.x, minp.y, minp.z}}, //LDF
	{(t_point){maxp.x, mid.y, mid.z}, (t_point){mid.x, minp.y, minp.z}} //RDF
	};

	*bbmax = loc_matrix[childnode_loc][0];
	*bbmin = loc_matrix[childnode_loc][1];
}

/*
	@brief Creates new child node and
		defines dimensions based on parent box (bbmin, bbmax)
*/
void	create_childnode(t_octree *root, t_nloc loc)
{
	t_point	child_bbmax;
	t_point	child_bbmin;

	if (root == NULL || loc > CHILDS_NUM)
		return ;
	root->childnode[loc] = create_octree(root, loc, LEAF);
	get_bbox_dimenesions(root, loc, &child_bbmax, &child_bbmin);
	octree_def_bbox(&root->childnode[loc], child_bbmin, child_bbmax);
}

/*
	@returns octree node if context is found inside the node objectlist
*/
t_octree	*find_generic(t_octree *root, void *context)
{
	if (root == NULL || context == NULL)
		return (NULL);
	if (ft_lst_getnode(root->objlist, context) != NULL)
		return (root);
	return (NULL);
}

/*
	Cleans octree nodes from elements inside objlist
*/
void	octree_empty_nodes(t_octree *root)
{
	ft_lstclear_nodes(&root->objlist);
}
