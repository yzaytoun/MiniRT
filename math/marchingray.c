/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marchingray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:12:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/25 13:26:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	swap_nodes_content(t_list **node_1, t_list **node_2)
{
	void	*temp;

	temp = (*node_1)->content;
	(*node_1)->content = (*node_2)->content;
	(*node_2)->content = temp;
}

static double	getdist(t_generic *cam, void *content)
{
	t_generic	*geom;

	if (content == NULL)
		return (-1);
	geom = (t_generic *)content;
	return (distance(cam->center, geom->center));
}

/*
	Sort object list by distance from context object
*/
//void	octreesort_objlist(t_octree *root, void *context)
//{
//	t_generic	*obj;		
//	t_list		*node;
//	double		distance_1;
//	double		distance_2;
//
//	if (root == NULL || ft_lstsize(root->objlist) <= 1)
//		return ;
//	obj = (t_generic *)context;
//	node = root->objlist;
//	//minimum distance
//	while (node->next != NULL)
//	{
//		distance_1 = getdist(obj, node->content);
//		distance_2 = getdist(obj, node->next->content);
//		if (distance_1 > 0 && distance_1 > 0 && distance_1 > distance_2)
//			swap_nodes_content(&node, &node->next);
//		node = node->next;
//	}
//}
