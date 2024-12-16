/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_element.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:12:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 10:17:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ELEMENT_H
# define RT_ELEMENT_H

# include "rt_struct.h"
# include "scene.h"

/* Element creation */
t_generic		*new_element(t_elementtype type);
t_generic		*create_element(t_elementtype type, char **in, void *dim);
void			delete_generic(void *content);
void			delete_geometry(void *content, void *context);
void			*copy_generic(void *generic);
t_dimensions	*new_dimension(void);
t_generic		*create_ambient(char **in);
t_generic		*create_camera(char **in);
t_generic		*create_light(char **in);

/* Geometry creation */
t_generic		*create_sphere(char **in);
t_generic		*create_plane(char **in);
t_generic		*create_cylinder(char **in);
t_generic		*create_cone(char **in);

/* Copy */
void			*copy_dimensions(void *dim, t_elementtype type);
t_dimensions	*copy_geometry_dimensions(t_dimensions *dim);
t_camera		*copy_camera_dimensions(t_camera *cam);

/* Intersect */

void			hit_element(t_scene *scene, int bounces);
t_color			hit_light(t_scene *scene);
void			trow_ray(t_scene *scene, int x, int y);
void			render(t_scene *scene);
//t_intersect		hit_geom(t_scene *scene, t_ray ray, t_generic *origin);
t_intersect		hit_geom(t_scene *scene, t_ray ray,
					t_generic *origin, t_bool update_lastnode);
t_intersect		hit_cone(t_generic *cone, t_ray ray);
t_intersect		hit_sphere(t_generic *sphere, t_ray ray);
t_intersect		hit_cylinder(t_generic *cylinder, t_ray ray);
t_intersect		hit_plane(t_generic *plane, t_ray ray);

/* Normal At */
t_point			normal_at_sphere(t_generic *sphere, t_point p);
t_point			normal_at_plane(t_generic *element, t_point p);
t_point			normal_at_cylinder(t_generic *cy, t_point p);
t_point			normal_at_cone(t_generic *cone, t_point p);

/* UV At*/
t_point			uv_at_plane(
					t_generic *geom, t_point at, t_point *u, t_point *v);
t_point			uv_at_sphere(
					t_generic *geom, t_point at, t_point *u, t_point *v);
t_point			uv_at_cylinder(
					t_generic *geom, t_point at, t_point *u, t_point *v);
t_point			uv_at_cone(t_generic *geom, t_point at, t_point *u, t_point *v);

/* Get Shape Boarders */
void			get_sphere_bbox(t_generic *generic);
/* Get Cone Or Cylinder Boarders */
void			get_ciruclar_prism_bbox(t_generic *generic);
void			get_plane_bbox(t_generic *generic);
t_bool			check_hit_bbox(t_ray ray, t_bbox bbox);

/* Modify */
void			update_element(
					t_scene *scene, t_generic *element, double vars[]);
void			update_dimensions(
					t_scene *scene, t_generic *element, double vars[]);
void			translate(t_scene *scene, t_generic *element, int key);
void			modify_dim(t_scene *scene, t_generic *element, int key);
void			rotate(t_scene *scene, t_generic *element, int key);
void			select_element(
					t_scene *scene, t_point point, t_elementtype type);
void			update_material(t_scene *scene, t_generic *element, int key);

/* Camera */
void			add_camera_viewport(t_generic *cam);
void			cam_control(t_scene *scene, t_generic *element);
void			rotate_cam(t_generic *cam, double angle_rad, int axis);
void			translate_cam(t_generic *cam, t_point coord, int key);

/* Lights */
t_color			mix_ambiance(t_generic *light, t_color color);
void			specular(t_scene *scene, t_ray ray, t_color *color);

#endif