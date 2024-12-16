/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:13:10 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/14 21:03:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*t_intersect	hit_geom(t_scene *scene, t_ray ray, t_generic *origin)
{
	t_list			*node;
	t_generic		*geom;
	t_intersect		hit;
	t_intersect		front;
	const double	t_min = 0.0001;

	node = scene->geometries;
	front.geom = NULL;
	front.t = -1;
	while (node)
	{
		hit.t = -1;
		geom = (t_generic *)node->content;
		if (geom && (!origin || (origin && origin->id != geom->id)))
			hit = geom->hit(geom, ray);
		if (hit.t > t_min && (hit.t < front.t || front.t == -1))
			front = hit;
		node = node->next;
	}
	if (front.t > t_min)
		front.point = ray.at(ray, front.t);
	return (front);
}
*/
/*
	// Usando procedural
	// t_point normal = mat.pnmap(mat.params, uv.x, uv.y);
	int ul = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W
		 - 1, uv.y * WIN_H + 1) & 255;
	int left = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W - 1, uv.y * WIN_H) & 255;
	int dl = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W
	 - 1, uv.y * WIN_H - 1) & 255;
	int up = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W, uv.y * WIN_H + 1) & 255;
	int down = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W, uv.y * WIN_H - 1) & 255;
	int ur = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W
	 + 1, uv.y * WIN_H + 1) & 255;
	int right = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W + 1, uv.y * WIN_H) & 255;
	int dr = my_mlx_pixel_get(mat.nmap, uv.x * WIN_W
	 + 1, uv.y * WIN_H - 1) & 255;
*/
static void	add_visual_effects(t_scene *scene, int bounce)
{
	t_point		inter;
	t_material	mat;
	t_point		reflx;
	t_calc		*calc;
	t_point		n_at;

	calc = &scene->calcs;
	inter = calc->front.point;
	mat = calc->front.geom->material;
	if (!bounce)
		calc->color = hit_light(scene);
	else
		calc->color = mix_color(
				calc->color,
				hit_light(scene),
				0.5 * calc->ray.from->material.reflx / bounce);
	if (mat.reflx && scene->add_reflex)
	{
		n_at = calc->front.geom->normal_at(calc->front.geom, inter);
		reflx = reflect_onplane(calc->ray.dir, n_at);
		scene->calcs.ray = create_ray(inter, reflx, calc->front.geom);
		if (scene->nav)
			scene->nav->moveto(&scene->nav, LAST_NODE);
		hit_element(scene, ++bounce);
	}
}

/* Ajuste de colores según el rebote realizado.
	El primer golpe toma el color del material.
	Los golpes sucesivos toman parte del color de la geometría.
	Cuando evalúa el primer rebote, verifica que exista luz specular.
*/
// else if (front.t == -1 && bounce)
// if (bounce == 1)
// specular(scene, scene->calcs.ray, &scene->calcs.color);
void	hit_element(t_scene *scene, int bounce)
{
	if (bounce >= scene->bounces)
		return ;
	scene->calcs.front = hit_geom(
			scene, scene->calcs.ray, scene->calcs.ray.from, FALSE);
	if (!bounce)
		scene->currfront = scene->calcs.front;
	if (scene->calcs.front.t > 0.0001)
		add_visual_effects(scene, bounce);
}
