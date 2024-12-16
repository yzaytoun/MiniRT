/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocate_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:45:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/22 19:32:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
	Sets content pointer to null without calling free
*/
static void	set_to_null(void *content)
{
	if (content == NULL)
		return ;
	content = NULL;
}

/*
	Updates element location inside the octree
*/
void	reallocate_element(t_scene *scene, t_generic *element)
{
	t_octree	*element_node;
	int			element_index;

	if (element == NULL || !scene->use_octree)
		return ;
	element_node = octree_getnode(scene->nav->root, find_generic, element);
	if (element_node)
	{
		element_index = ft_lst_getnode_index(element_node->objlist, element, 0);
		ft_lstdel_index(&element_node->objlist, set_to_null, element_index);
		octreeiter_context(scene->nav->root, octreeinsert, element);
	}
}
