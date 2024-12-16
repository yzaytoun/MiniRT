/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_neighbour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:47:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/25 16:04:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_index(double val)
{
	int	res;

	res = 0;
	if (val >= 0)
		res = 1;
	else if (val < 0)
		res = 2;
	return (res);
}

void	get_neighbours_from_ray(int (*neighbours)[], t_point ray_dir)
{
	const int	loc_matrix_x[3] = {NEMPTY, NRIGHT, NLEFT};
	const int	loc_matrix_y[3] = {NEMPTY, NFRONT, NBACK};
	const int	loc_matrix_z[3] = {NEMPTY, NUP, NDOWN};

	(*neighbours)[0] = loc_matrix_x[get_index(ray_dir.x)];
	(*neighbours)[1] = loc_matrix_y[get_index(ray_dir.y)];
	(*neighbours)[2] = loc_matrix_z[get_index(ray_dir.z)];
}

/*
	Navigate Octree to and find intersection between ray and Node neighbours
*/
t_octree	*get_next_neighbour(t_octree *node, t_ray ray)
{
	int			count;
	int			neighbours_arr[6];
	t_octree	*neighbour_node;
	t_bool		intersected;

	if (!node)
		return (NULL);
	get_neighbours_from_ray(&neighbours_arr, ray.dir);
	count = -1;
	intersected = FALSE;
	neighbour_node = NULL;
	while (++count < NEIGHBOURS_NUM)
	{
		if (node->neighbour[neighbours_arr[count]])
		{
			intersected = check_hit_bbox(
					ray, node->neighbour[neighbours_arr[count]]->bbox);
			if (intersected)
				neighbour_node = node->neighbour[neighbours_arr[count]];
		}
	}
	return (neighbour_node);
}
