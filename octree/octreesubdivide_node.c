/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octreesubdivide_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:19:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/23 20:24:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_octree	*get_neighbour_pointer(int loc[], t_octree *parent)
{
	if (parent != NULL)
	{
		if (loc[0] == PARENT)
			return (parent->neighbour[loc[1]]);
		else if (loc[0] == CHILD)
			return (parent->childnode[loc[1]]);
	}
	return (NULL);
}

static void	get_loc_keys(
	t_nloc childnode_loc, t_neighbour neighbour_loc, int (*loc_keys)[])
{
	const int	loc_matrix[CHILDS_NUM][NEIGHBOURS_NUM][2] = {
		//	NLEFT, NRIGHT, NUP, NDOWN, NFRONT, NBACK
	{{PARENT, NLEFT}, {CHILD, RUB}, {PARENT, NUP},
	{CHILD, LDB}, {CHILD, LUF}, {PARENT, BACK}}, /*LUB*/
	{{CHILD, LUB}, {PARENT, NRIGHT}, {PARENT, NUP},
	{CHILD, RDB}, {CHILD, RUF}, {PARENT, BACK}}, /*RUB*/
	{{PARENT, NLEFT}, {CHILD, RDB}, {CHILD, LUB},
	{PARENT, NDOWN}, {CHILD, LDF}, {PARENT, BACK}}, /*LDB*/
	{{CHILD, LDB}, {PARENT, NRIGHT}, {CHILD, RUB},
	{PARENT, NDOWN}, {CHILD, RDF}, {PARENT, BACK}}, /*RDB*/
	{{PARENT, NLEFT}, {CHILD, RUF}, {PARENT, NUP},
	{CHILD, LDF}, {PARENT, NFRONT}, {CHILD, LUB}}, /*LUF*/
	{{CHILD, LUF}, {PARENT, NRIGHT}, {PARENT, NUP},
	{CHILD, RDF}, {PARENT, NFRONT}, {CHILD, RUB}}, /*RUF*/
	{{PARENT, NLEFT}, {CHILD, RDF}, {CHILD, LUF},
	{PARENT, NDOWN}, {PARENT, NFRONT}, {CHILD, LDB}}, /*LDF*/
	{{CHILD, LDF}, {PARENT, NRIGHT}, {CHILD, RUF},
	{PARENT, NDOWN}, {PARENT, NFRONT}, {CHILD, RDB}} /*RDF*/
	};

	(*loc_keys)[0] = loc_matrix[childnode_loc][neighbour_loc][0];
	(*loc_keys)[1] = loc_matrix[childnode_loc][neighbour_loc][1];
}

static void	set_neighbours(t_octree **childnode)
{
	int		loc[2];

	if ((*childnode) == NULL)
		return ;
	get_loc_keys((*childnode)->nodeloc, NLEFT, &loc);
	(*childnode)->neighbour[NLEFT]
		= get_neighbour_pointer(loc, (*childnode)->parent);
	get_loc_keys((*childnode)->nodeloc, NRIGHT, &loc);
	(*childnode)->neighbour[NRIGHT]
		= get_neighbour_pointer(loc, (*childnode)->parent);
	get_loc_keys((*childnode)->nodeloc, NUP, &loc);
	(*childnode)->neighbour[NUP]
		= get_neighbour_pointer(loc, (*childnode)->parent);
	get_loc_keys((*childnode)->nodeloc, NDOWN, &loc);
	(*childnode)->neighbour[NDOWN]
		= get_neighbour_pointer(loc, (*childnode)->parent);
	get_loc_keys((*childnode)->nodeloc, NFRONT, &loc);
	(*childnode)->neighbour[NFRONT]
		= get_neighbour_pointer(loc, (*childnode)->parent);
	get_loc_keys((*childnode)->nodeloc, NBACK, &loc);
	(*childnode)->neighbour[NBACK]
		= get_neighbour_pointer(loc, (*childnode)->parent);
}

/*
	Subdivide root and turns it into parent node
*/
void	octreesubdivide_node(t_octree **root)
{
	int	index;

	index = -1;
	if (root == NULL || (*root) == NULL)
		return ;
	(*root)->nodetype = NODE;
	(*root)->nodeloc = PARENT;
	while (++index < CHILDS_NUM)
		create_childnode((*root), index);
	index = -1;
	while (++index < CHILDS_NUM)
		set_neighbours(&(*root)->childnode[index]);
}
