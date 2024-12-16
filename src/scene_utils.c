/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:00:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 13:57:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_id(void *content)
{
	t_generic	*geom;
	static int	id = 0;

	if (!content)
		return ;
	geom = (t_generic *)content;
	geom->id = id++;
}

void	init_bbox(void *content)
{
	t_generic	*generic;

	if (!content)
		return ;
	generic = (t_generic *)content;
	if (generic->type != PLANE)
		generic->get_bbox_boundaries(generic);
}

t_bool	is_geometry(t_elementtype type)
{
	if (type != CAMERA && type != LIGHT && type != AMBIENT)
		return (TRUE);
	return (FALSE);
}
