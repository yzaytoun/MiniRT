/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octreeinsert_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:34:33 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 16:14:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "octree.h"
#include "rt_struct.h"

/*
	Inserts geometry from objectlist into octree nodes
	@note One geomerty can be inserted into many nodes
*/
void	octreeinsert_geometry(t_octree *root, t_list *objectlist)
{
	t_list	*node;

	if (root == NULL || objectlist == NULL)
		return ;
	node = objectlist;
	while (node != NULL)
	{
		octreeiter_context(root, octreeinsert, node->content);
		node = node->next;
	}
}

static void	octree_cam_insert(t_octree **root, t_generic *cam, int *res)
{
	int	index;

	index = -1;
	while (++index < CHILDS_NUM)
	{
		if ((*root)->childnode[index])
		{
			if (point_inside_node(cam->center,
					(*root)->childnode[index]->bbox.bbmax,
					(*root)->childnode[index]->bbox.bbmin))
			{
				ft_lstinsert(&(*root)->childnode[index]->objlist, cam, BACK);
				*res = TRUE;
				break ;
			}
		}
	}
}

/*
	Inserts cameras from list into octree nodes
	@note One camera can be inserted into one node
*/
void	octreeinsert_cameras(t_octree *root, t_list *cameralist)
{
	t_list		*node;
	t_generic	*cam;
	int			res;

	res = FALSE;
	if (root == NULL || cameralist == NULL)
		return ;
	node = cameralist;
	while (node != NULL)
	{
		res = FALSE;
		cam = (t_generic *)node->content;
		octree_cam_insert(&root, cam, &res);
		node = node->next;
	}
	if (!res)
		ft_lstinsert(&root->objlist, cam, BACK);
}
