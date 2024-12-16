/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:58:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/14 19:29:53 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	destroy_scene(t_scene *scene)
{
	if (scene == NULL)
		return ;
	mnx_destroy(&scene->mnx);
	mlx_destroy_image(scene->mlx->mlx, scene->mlx->img.ptr);
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->win);
	ft_lstclear_context(&scene->geometries, delete_geometry, scene->mlx->mlx);
	ft_lstclear(&scene->cameras, delete_generic);
	ft_lstclear(&scene->d_lights, delete_generic);
	if (scene->a_light)
		delete_generic(scene->a_light);
	destroy_geomatrix(&scene->geomatrix);
}

void	exit_scene(t_backup *backup)
{
	destroy_octree(&backup->scene->nav->root);
	destroy_octreenav(&backup->scene->nav);
	destroy_scene(backup->scene);
	destroy_backup(&backup);
	exit(EXIT_SUCCESS);
}
