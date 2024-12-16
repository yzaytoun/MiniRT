/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:33:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 16:45:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCTREE_H
# define OCTREE_H

# include <stdio.h>
# include <stdlib.h>
# include "rt_math.h"
# include "rt_macros.h"
# include "libft.h"

# define CHILDS_NUM  8
# define VERTICES_NUM  8
# define NEIGHBOURS_NUM 6

typedef struct s_octree		t_octree;
typedef enum e_ntype		t_ntype;
typedef enum e_neighbour	t_neighbour;
typedef enum e_nloc			t_nloc;

/*
	***** Back ****
	LUB -> Left Up Back
	RUB -> Right Up Back
	LDB -> Left Down Back
	RDB -> Right Down Back
	***** Front ****
	LUF -> Left Up Front
	RUF -> Right Up Front
	LDF -> Left Down Front
	RDF -> Right Down Front
*/
enum e_nloc
{
	LUB,
	RUB,
	LDB,
	RDB,
	LUF,
	RUF,
	LDF,
	RDF,
	PARENT,
	CHILD
};

enum e_neighbour
{
	NLEFT,
	NRIGHT,
	NUP,
	NDOWN,
	NFRONT,
	NBACK,
	NEMPTY = -1
};

enum e_ntype
{
	LEAF,
	NODE
};

struct s_octree
{
	t_bbox		bbox;
	t_point		center;
	t_list		*objlist;
	t_ntype		nodetype;
	t_nloc		nodeloc;
	t_octree	*childnode[8];
	t_octree	*neighbour[6];
	t_octree	(*parent);
};

/* OCTREE */

t_octree	*create_octree(t_octree *parent,
				t_nloc nodeloc, t_ntype nodetype);
void		destroy_octree(t_octree **root);
void		octreesubdivide_node(t_octree **root);
void		octree_def_bbox(
				t_octree **root, t_point min_point, t_point max_point);
t_octree	*octree_getnode(t_octree *root,
				t_octree *(*func)(t_octree *, void *), void *context);
void		octreeinsert(t_octree *node, void *context);
void		octreeinsert_geometry(t_octree *root, t_list *objectlist);
void		octreeinsert_cameras(t_octree *root, t_list *cameralist);
t_bool		point_inside_node(t_point point, t_point bbmax, t_point bbmin);
void		print_nodeloc(int type);
void		octree_log(t_octree *root);

/* Iterators */

void		octreeiter(t_octree *node, void (*f)(t_octree *));
void		octreeiter_context(t_octree *node,
				void (*f)(t_octree *, void *context), void *context);
void		octreeiter_neighbours(t_octree *node, void (*f)(t_octree *));
void		octreeiter_neighbours_context(t_octree *node,
				void (*f)(t_octree *, void *context), void *context);
void		octreeiter_childnodes(t_octree *node, void (*f)(t_octree *));

/* Utils */

void		octree_setnodes_tonull(t_octree *root);
void		create_childnode(t_octree *root, t_nloc loc);
void		octree_empty_nodes(t_octree *root);

#endif
