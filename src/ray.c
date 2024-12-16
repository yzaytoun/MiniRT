/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:13:04 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/14 21:10:27 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
	@param t hit distance
*/
t_point	ray_at(t_ray ray, double t)
{
	return (vectors_sum(ray.origin, vector_multiply(ray.dir, t)));
}

/*
	@param origin Ray origin
	@param direction Ray direction
	@param geom Geometry from which the ray originates
*/
t_ray	create_ray(t_point origin, t_point direction, t_generic *geom)
{
	t_ray	ray;

	ray.from = geom;
	ray.origin = origin;
	ray.dir = direction;
	ray.at = ray_at;
	return (ray);
}

t_point	sphere_point_polar(double vangle, double hangle)
{
	t_point	p;

	p.x = sin(vangle) * cos(hangle);
	p.y = sin(vangle) * sin(hangle);
	p.z = cos(vangle);
	return (p);
}

t_point	rotate_on_vector(t_point n, double t, t_point p)
{
	int	sign;

	if (t > M_PI)
		sign = -1;
	else
		sign = 1;
	return (vectors_sum(
			vectors_sum(
				vector_multiply(n,
					dot_product(n, p)),
				vector_multiply(vectors_res(p,
						vector_multiply(n, dot_product(n, p))),
					cos(t))), vector_multiply(cross_product(n, p),
				sign * sin(t))));
}

/* double vangle = cam_dim->vfield + cam_dim->vp.dav *
	(double)y + cam_dim->orientation.x;
	TODO ROTAR EL ANGULO FINAL DEL VECTOR con cam_dim->orientation.z
		Y DESPLAZAR ESTE SIEMPRE EN EL RANGO 0 < vangle < 180
	t_point new_dir = get_rotation_vector(cam_dim->vp.right, 
		vangle, cam_dim->dir);
*/
void	trow_ray(t_scene *scene, int x, int y)
{
	const t_camera	*cam_dim = (t_camera *)scene->a_cam->dim;
	const double	hangle = -cam_dim->hfield * 0.5 + cam_dim->vp.dau
		* (double)x + cam_dim->orientation.x;
	const double	vangle = -cam_dim->vfield * 0.5 + cam_dim->vp.dav
		* (double)y + M_PI_2;
	t_point			raydir;

	raydir = sphere_point_polar(vangle, hangle);
	raydir = rotate_on_vector(cam_dim->right, cam_dim->orientation.z, raydir);
	scene->calcs.ray = create_ray(scene->a_cam->center, raydir, NULL);
	scene->calcs.color = scene->a_light->material.color;
	update_octreenav(scene, FALSE);
	hit_element(scene, 0);
	if (scene->geomatrix)
		scene->geomatrix->matrix[y][x] = scene->currfront.geom;
	my_mlx_pixel_put(&scene->mlx->img, x, y, color_int(scene->calcs.color));
}
