/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:13:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/14 21:05:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_backup	*create_backup(t_scene *scene)
{
	t_backup	*backup;

	backup = malloc(sizeof(t_backup));
	if (backup == NULL)
		return (NULL);
	backup->scene = scene;
	backup->geometry_list
		= ft_lstmap_context(scene->geometries,
			copy_generic, delete_geometry, scene->mlx->mlx);
	backup->camera_list
		= ft_lstmap(scene->cameras, copy_generic, delete_generic);
	backup->light_list
		= ft_lstmap(scene->d_lights, copy_generic, delete_generic);
	backup->a_light = copy_generic(scene->a_light);
	return (backup);
}

void	destroy_backup(t_backup **backup)
{
	if (backup == NULL || (*backup) == NULL)
		return ;
	ft_lstclear_context(&(*backup)->geometry_list,
		delete_geometry, (*backup)->scene->mlx->mlx);
	ft_lstclear(&(*backup)->camera_list, delete_generic);
	ft_lstclear(&(*backup)->light_list, delete_generic);
	delete_generic((*backup)->a_light);
	free((*backup)->scene->mlx->mlx);
	(*backup)->scene->mlx->mlx = NULL;
	free((*backup)->scene->mlx);
	(*backup)->scene->mlx = NULL;
	free((*backup));
}

void	check_reset(t_backup *backup)
{
	if (backup == NULL)
		return ;
	if (backup->scene->reset == TRUE)
	{
		backup_reset(backup, backup->scene);
		render(backup->scene);
		backup->scene->reset = FALSE;
	}
}

/*
	Empty octree nodes and insert objects to the initial state
*/
void	octree_reset(t_scene *scene)
{
	if (scene->nav)
	{
		octreeiter(scene->nav->root, octree_empty_nodes);
		octreeinsert_geometry(scene->nav->root, scene->geometries);
		octreeinsert_cameras(scene->nav->root, scene->cameras);
	}
}

void	backup_reset(t_backup *backup, t_scene *scene)
{
	ft_lstclear_context(&scene->geometries, delete_geometry, scene->mlx->mlx);
	ft_lstclear(&scene->cameras, delete_generic);
	ft_lstclear(&scene->d_lights, delete_generic);
	delete_generic(scene->a_light);
	scene->geometries = ft_lstmap_context(
			backup->geometry_list,
			copy_generic, delete_geometry, scene->mlx->mlx);
	scene->cameras = ft_lstmap(
			backup->camera_list, copy_generic, delete_generic);
	scene->d_lights = ft_lstmap(
			backup->light_list, copy_generic, delete_generic);
	scene->a_cam = (t_generic *)scene->cameras->content;
	scene->a_light = copy_generic(backup->a_light);
	scene->selected = NULL;
	scene->add_reflex = FALSE;
	scene->selected_index = 0;
	scene->bounces = BOUNCE_LIMIT;
	octree_reset(scene);
}
