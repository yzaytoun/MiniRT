/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octreenav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:41:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 16:15:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	nav_moveto(t_octreenav **nav, t_updatekey startfrom)
{
	if (startfrom == LAST_NODE && (*nav)->lastnode)
		(*nav)->currnode = (*nav)->lastnode;
	else if (startfrom == ROOT_NODE)
		(*nav)->currnode = (*nav)->root;
	else if (startfrom == CAM_NODE && (*nav)->camnode)
		(*nav)->currnode = (*nav)->camnode;
	else
		(*nav)->currnode = NULL;
	(*nav)->startfrom = startfrom;
}

/*
	Create an octree navigator
*/
t_octreenav	*create_octreenav(t_octree *root)
{
	t_octreenav	*nav;

	nav = malloc(sizeof(t_octreenav));
	if (nav == NULL)
		return (NULL);
	nav->root = root;
	nav->moveto = nav_moveto;
	nav->currnode = NULL;
	nav->lastnode = NULL;
	nav->camnode = NULL;
	nav->cam = NULL;
	return (nav);
}

/*
	Destroy an octree navigator
*/
void	destroy_octreenav(t_octreenav **nav)
{
	if (nav == NULL || (*nav) == NULL)
		return ;
	free(*nav);
}

/*
	Find camera in octree and update camnode, and move nav pointer to camnode
*/
void	update_octreenav(t_scene *scene, t_bool update_camnode)
{
	t_octreenav	*nav;
	t_list		*node;

	nav = scene->nav;
	if (nav && scene->use_octree && nav->root)
	{
		if (update_camnode && (!nav->cam || nav->cam != scene->a_cam))
		{
			nav->camnode
				= octree_getnode(nav->root, find_generic, scene->a_cam);
			if (nav->camnode)
			{
				node = ft_lst_getnode(
						nav->camnode->objlist, scene->a_cam);
				if (node)
					nav->cam = (t_generic *)node->content;
			}
		}
		nav->moveto(&nav, CAM_NODE);
		nav->lastnode = nav->currnode;
	}
}
