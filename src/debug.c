/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:27:07 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 14:58:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

void	print_point(const char *p_name, t_point p)
{
	if (p_name)
		printf("%s {x: %f y: %f z: %f}\n", p_name, p.x, p.y, p.z);
	else
		printf("{x: %f y: %f z: %f}\n", p.x, p.y, p.z);
}

void	print_color(const char *c_name, t_color c)
{
	if (c_name)
		printf("%s {r: %d g: %d b: %d} | color int = %d\n", c_name,
			c.r, c.g, c.b, color_int(c));
	else
		printf("r: %d g: %d b: %d | color int = %d\n",
			c.r, c.g, c.b, color_int(c));
}

void	printerror(const char *str)
{
	if (str == NULL)
		perror("Error");
	else
	{
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	print_scene_elements(t_scene scene)
{
	t_generic	*g;
	t_list		*node;

	node = scene.geometries;
	while (node)
	{
		g = (t_generic *)node->content;
		if (g)
		{
			print_elementtype(g->type);
			generic_bbox_log(g);
		}
		node = node->next;
	}
}

void	print_camview(t_generic *cam)
{
	t_camera	*cam_dim;

	cam_dim = (t_camera *)cam->dim;
	printf("--------------- View Port ---------------\n");
	print_point("Cam center", cam->center);
	printf("hfield = %f\n", cam_dim->hfield);
	printf("vfield = %f\n", cam_dim->vfield);
	print_point("Dir", cam_dim->dir);
	print_point("look from(center)", cam->center);
	print_point("Look at", cam_dim->look_at);
	print_point("du ", cam_dim->vp.du);
	print_point("dv ", cam_dim->vp.dv);
	printf("dau %f\n", to_degrees(cam_dim->vp.dau));
	printf("dav %f\n", to_degrees(cam_dim->vp.dav));
	printf("angle x %f\n", to_degrees(cam_dim->orientation.x));
	printf("angle y %f\n", to_degrees(cam_dim->orientation.y));
	printf("angle z %f\n", to_degrees(cam_dim->orientation.z));
	print_point("pixel0 ", cam_dim->vp.pixel0);
	print_point("upperleft ", cam_dim->vp.upper_left);
	print_point("right ", cam_dim->vp.right);
	print_point("up ", cam_dim->vp.vup);
	printf("------------------------------\n");
}
