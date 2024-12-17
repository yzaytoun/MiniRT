/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:19:00 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/17 09:35:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

void	add_mlx(t_scene *scene, char *title)
{
	t_mlx		*mlx;

	mlx = malloc(sizeof(t_mlx));
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		printerror("MLX Object");
	if (title == NULL)
		mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "MiniRT");
	else
		mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, title);
	if (mlx->win == NULL)
		printerror("MLX Window");
	scene->mlx = mlx;
	mlx->img = mnx_img_new(mlx->mlx, WIN_W, WIN_H);
}

void	add_element(t_scene *scene, t_input *in)
{
	if (in == NULL)
		return ;
	if (in->type == AMBIENT)
	{
		scene->a_light = create_ambient(in->inputs);
		scene->light_count++;
	}
	else if (in->type == CAMERA)
	{
		ft_lstinsert(&scene->cameras, create_camera(in->inputs), FRONT);
		scene->cam_count++;
	}
	else if (in->type == LIGHT)
	{
		ft_lstinsert(&scene->d_lights, create_light(in->inputs), FRONT);
		scene->light_count++;
	}
	else if (in->type == SPHERE)
		ft_lstinsert(&scene->geometries, create_sphere(in->inputs), FRONT);
	else if (in->type == PLANE)
		ft_lstinsert(&scene->geometries, create_plane(in->inputs), FRONT);
	else if (in->type == CYLINDER)
		ft_lstinsert(&scene->geometries, create_cylinder(in->inputs), FRONT);
	else if (in->type == CONE)
		ft_lstinsert(&scene->geometries, create_cone(in->inputs), FRONT);
}

void	scene_init(t_scene *scene)
{
	scene->a_light = NULL;
	scene->a_cam = NULL;
	scene->geometries = NULL;
	scene->d_lights = NULL;
	scene->cameras = NULL;
	scene->mlx = NULL;
	scene->geomatrix = new_geomatrix(WIN_H, WIN_W);
	scene->selected = NULL;
	scene->menu_color = create_color(MENU_COLOR, MENU_COLOR, MENU_COLOR);
	scene->bounces = BOUNCE_LIMIT;
	scene->use_octree = FALSE;
	scene->add_reflex = FALSE;
	scene->add_smooth = FALSE;
	scene->check_geom_bbox = FALSE;
	scene->nav = NULL;
}

t_bool	elements_check(t_scene *scene)
{
	if (!scene->a_light || !scene->cameras)
		return (FALSE);
	return (TRUE);
}

t_scene	create_scene(t_list *elements)
{
	t_list	*node;
	t_input	*in;
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	if (elements == NULL)
		return (scene);
	scene_init(&scene);
	node = elements;
	while (node)
	{
		in = (t_input *)node->content;
		add_element(&scene, in);
		node = node->next;
	}
	if (!elements_check(&scene))
		printerror("Missing Elements in scene !!");
	if (scene.cameras && scene.cameras->content)
		scene.a_cam = (t_generic *)scene.cameras->content;
	ft_lstiter(scene.geometries, add_id);
	ft_lstiter(scene.geometries, init_bbox);
	scene.geom_count = ft_lstsize(scene.geometries);
	return (scene);
}
