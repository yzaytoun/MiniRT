/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:37:57 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 18:52:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rt_struct.h"
# include "octree.h"

typedef struct s_scene
{
	t_mlx			(*mlx);
	t_generic		*a_light;
	t_generic		*a_cam;
	t_list			*geometries;
	t_list			*d_lights;
	t_list			*cameras;
	t_material		materials[20];
	int				light_count;
	int				cam_count;
	int				geom_count;
	int				bounces;
	t_geomatrix		*geomatrix;
	t_intersect		currfront;
	t_generic		(*selected);
	int				selected_index;
	t_mnx			mnx;
	t_color			*target_color;
	t_color			menu_color;
	t_octreenav		(*nav);
	t_bool			use_octree;
	t_bool			reset;
	t_bool			add_reflex;
	t_calc			calcs;
	t_bool			print_log;
	t_bool			add_smooth;
	t_bool			check_geom_bbox;
}	t_scene;

typedef struct s_backup
{
	t_scene		*scene;
	t_list		*geometry_list;
	t_list		*camera_list;
	t_list		*light_list;
	t_generic	*a_light;
}	t_backup;

/* Scene */
t_scene			create_scene(t_list *elements);
void			add_id(void *content);
void			init_bbox(void *content);
void			destroy_scene(t_scene *scene);
void			add_element(t_scene *scene, t_input *in);
void			add_mlx(t_scene *scene, char *title);
void			exit_scene(t_backup *backup);

/* Backup */
t_backup		*create_backup(t_scene *scene);
void			destroy_backup(t_backup **backup);
void			backup_reset(t_backup *backup, t_scene *scene);
void			check_reset(t_backup *backup);

/* Navigator */
t_octreenav		*create_octreenav(t_octree *root);
void			destroy_octreenav(t_octreenav **nav);
t_octree		*find_generic(t_octree *root, void *context);
void			update_octreenav(t_scene *scene, t_bool update_camnode);

/* Octree RayTracer */
void			octree_init(t_scene *scene);
void			octree_reset(t_scene *scene);
void			reallocate_element(t_scene *scene, t_generic *element);
t_octree		*get_next_neighbour(t_octree *node, t_ray ray);

/* Matrix */
void			destroy_geomatrix(t_geomatrix **geomatrix);
t_geomatrix		*new_geomatrix(int nrows, int ncolumns);

/* Utils */
t_bool			is_geometry(t_elementtype type);

#endif // SCENE_H
