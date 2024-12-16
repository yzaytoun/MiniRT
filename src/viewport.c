/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:01:38 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 16:29:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	get_view_dimensions(
	t_viewport *view, t_generic *cam, double focal_length, t_point lookat)
{
	t_point	w;
	t_point	v;
	t_point	u;

	w = normalize(vectors_res(cam->center, lookat));
	u = normalize(cross_product(create_point(0, 0, 1), w));
	v = normalize(cross_product(w, u));
	view->u = vector_multiply(u, view->width);
	view->v = vector_multiply(v, -view->height);
	view->du = vector_multiply(view->u, 1.0 / (double)WIN_W);
	view->dv = vector_multiply(view->v, 1.0 / (double)WIN_H);
	view->upper_left = vectors_res(cam->center,
			vectors_sum(vector_multiply(w, focal_length),
				vectors_sum(vector_multiply(view->u, 0.5),
					vector_multiply(view->v, 0.5))));
	view->pixel0 = vectors_sum(view->upper_left,
			vector_multiply(vectors_sum(view->du, view->dv), 0.5));
}

//TODO Dir doesnt have to change on displacements.
void	add_camera_viewport(t_generic *cam)
{
	t_viewport	view;
	t_camera	*cam_dim;

	cam_dim = (t_camera *)cam->dim;
	view.vup = create_point(0, 0, 1);
	cam_dim->dir = vectors_res(cam_dim->new_look_at, cam->center);
	cam_dim->new_look_at = vectors_sum(cam->center, cam_dim->dir);
	cam_dim->vp.dau = cam_dim->hfield / (double)WIN_W;
	cam_dim->vp.dav = cam_dim->vfield / (double)WIN_H;
	get_view_dimensions(&cam_dim->vp,
		cam, cam_dim->focal, cam_dim->new_look_at);
}
