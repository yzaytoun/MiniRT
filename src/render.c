/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:18:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 09:31:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	paint_it_black(t_scene *scene, int x, int y)
{
	my_mlx_pixel_put(&scene->mlx->img, x, y, 0);
}

void	render(t_scene *scene)
{
	t_camera	*cam_dim;
	t_point		dir;	

	cam_dim = (t_camera *)scene->a_cam->dim;
	dir = sphere_point_polar(cam_dim->orientation.z, cam_dim->orientation.x);
	cam_dim->right = normalize(cross_product(create_point(0, 0.01, 0.99), dir));
	update_octreenav(scene, TRUE);
	scene_img_iter(scene, trow_ray);
	if (scene->add_smooth)
		scene_img_iter(scene, smooth);
	mlx_put_image_to_window(scene->mlx->mlx,
		scene->mlx->win, scene->mlx->img.ptr, 0, 0);
	mnx_img_to_img(&scene->mnx.img, &scene->mlx->img, (t_point2D){0, 0});
}

/*
	@brief Change pixels color taking 60% of
	current pixel and 10% of surrounding pixels 
*/
void	smooth(t_scene *scene, int x, int y)
{
	t_color	color[5];

	if (!x || !y || x >= WIN_W - 1 || y >= WIN_H - 1)
		return ;
	color[0] = color_at(scene->mlx->img, x, y);
	color[1] = color_at(scene->mlx->img, x + 1, y);
	color[2] = color_at(scene->mlx->img, x - 1, y);
	color[3] = color_at(scene->mlx->img, x, y + 1);
	color[4] = color_at(scene->mlx->img, x, y - 1);
	color[0].r = (color[0].r * 6 + color[1].r
			+ color[2].r + color[3].r + color[4].r) * 0.1;
	color[0].g = (color[0].g * 6 + color[1].g
			+ color[2].g + color[3].g + color[4].g) * 0.1;
	color[0].b = (color[0].b * 6 + color[1].b
			+ color[2].b + color[3].b + color[4].b) * 0.1;
	my_mlx_pixel_put(&scene->mlx->img, x, y, color_int(color[0]));
}

/* Temporal function to paint background in diferent ways */
void	paint_background(t_scene *scene, t_point p, t_ray ray, int mode)
{
	t_point	ray_dir;
	t_point	c;
	double	a;

	ray_dir = normalize(ray.dir);
	if (mode)
	{
		a = 0.5 * (ray_dir.y + 1.0);
		c = vectors_sum(vector_multiply(
					create_point(1, 1, 1), 1.0 - a),
				vector_multiply(create_point(0.5, 0.7, 1.0), a));
		my_mlx_pixel_put(&scene->mlx->img, p.x, p.y,
			color_int(vector_to_color(c)));
		return ;
	}
	ray_dir = vector_multiply(
			create_point(ray_dir.x + 1, ray_dir.y + 1, ray_dir.z + 1), 0.5);
	my_mlx_pixel_put(&scene->mlx->img, p.x, p.y,
		color_int(vector_to_color(ray_dir)));
}
