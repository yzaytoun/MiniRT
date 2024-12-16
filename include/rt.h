/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:04:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/25 16:12:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "rt_struct.h"
# include "rt_math.h"
# include "dict.h"
# include "ui.h"
# include "mnx_menu.h"
# include "rt_element.h"

/* Utils */
int				normal_check(t_point point);
t_bool			valid_fileformat(const char *filename);
t_bool			isvalid_color(t_color color);

/* Hooks */
void			launch_window_hook(t_scene *scene);
int				hook_exit(t_backup *backup);
int				hook_keypress(int key, t_backup *backup);
int				hook_mousemove(int x, int y, t_scene *scene);
int				hook_mousepress(int button, int x, int y, t_scene *scene);
int				hook_mouserelease(int button, int x, int y, t_scene *scene);

/* Image */
void			scene_img_iter(
					t_scene *scene, void (*f)(t_scene *scene, int x, int y));
void			img_iter(t_mlximg *img, void (*f)(t_mlximg *img, int x, int y));
void			paint_it_black(t_scene *scene, int x, int y);
void			smooth(t_scene *scene, int x, int y);

/* REVISAR*/
//void			img_new(t_mlx **mlx);
t_mlximg		*create_img(t_mlx *mlx);
t_mlximg		image_load(void *mlx, char *file);

/* Ray */
t_point			ray_at(t_ray ray, double t);
t_ray			create_ray(t_point origin, t_point direction,
					t_generic *geom);

/* Vectors operations */
t_point			reflect_onplane(t_point incident, t_point normal);
t_point			create_point(double x, double y, double z);
t_point			to_first_octant(t_point vector);
t_point			random_bounce(t_point vector);
t_point			random_vector(void);

/* Color */
t_color			create_color(double r, double g, double b);
t_color			mix_color(t_color a, t_color b, double factor);
t_color			sum_color(t_color a, t_color b);
void			modify_color(t_color *oldcolor, t_color newcolor);
t_color			vector_to_color(t_point	vector);
t_point			color_to_vector(t_color	color);
int				color_int(t_color color);
t_color			int_to_color(int c);
t_color			color_at(t_mlximg image, int x, int y);
double			color_alpha(t_color color);

/* Materials */
t_color			material_color(t_intersect inter);
t_point			uv_at(t_point p, t_generic *geom, t_point *u, t_point *v);
void			bumb_to_normal(t_mlximg *img, void *data, int x, int y);
void			clear_material(t_material *mat, void *mlx);
void			add_mat_ckrparam(t_material *mat, void *mlx);
void			add_mat_prlparam(t_material *mat);

t_mlximg		*create_img(t_mlx *mlx);
void			img_iter_context(t_mlximg *img, void *data,
					void (*f)(t_mlximg *img, void *data, int x, int y));
void			checkerboard(void *data, t_mlximg *img, int x, int y);
int				checkerboard2(void *data, double x, double y);
double			distance(t_point p1, t_point p2);
double			projection_length(t_point v, t_point u);
t_intersect		create_intersect(double t, t_generic *geom);

/* Interface */
int				bar_value(void *pb, int x, int y, int progress);
void			rotate_vector(
					t_point *vector, double angle_rad, t_axis axis);
void			get_vector_angles(t_point v, double *hangle, double *vangle);

/* Debug */
void			print_point(const char *p_name, t_point p);
void			print_color(const char *c_name, t_color c);
void			printerror(const char *str);
void			print_elementtype(t_elementtype type);
void			print_scene_elements(t_scene scene);
void			print_camview(t_generic *cam);
void			ray_log(t_ray ray, double t);
void			generic_log(t_generic *generic, t_bool show_bbox);
void			dimensions_log(t_dimensions *dim, t_elementtype type);
void			generic_bbox_log(t_generic *generic);
void			print_perl_params(t_perlparam *param);
void			print_material(t_material mat);
#endif