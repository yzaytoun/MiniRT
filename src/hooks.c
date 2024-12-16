/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:44:48 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/16 10:12:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/* Exit when pressing 'x' on mlx window */
int	hook_exit(t_backup *backup)
{
	exit_scene(backup);
	return (EXIT_SUCCESS);
}

void	render_config(t_scene *scene, int key)
{
	if (key == XK_o)
		scene->use_octree = !scene->use_octree;
	else if (key == XK_m)
		scene->bounces += 1;
	else if (key == XK_n)
		scene->bounces -= 1;
	else if (key == XK_comma)
		scene->add_reflex = !scene->add_reflex;
	else if (key == XK_minus)
		scene->print_log = !scene->print_log;
	else if (key == XK_greater)
		scene->add_smooth = !scene->add_smooth;
}

void	select_index(t_scene *scene, int key)
{
	int			count;
	const int	numkeys[10]
		= {XK_0, XK_1, XK_2, XK_3, XK_4, XK_5, XK_6, XK_7, XK_8, XK_9};

	count = -1;
	while (++count < 10)
	{
		if (key == numkeys[count])
			scene->selected_index = count;
	}
}

int	hook_keypress(int key, t_backup *backup)
{
	t_scene	*scene;

	scene = backup->scene;
	if (key == XK_Escape)
		exit_scene(backup);
	else if (key == XK_r)
		scene->reset = TRUE;
	check_reset(backup);
	render_config(scene, key);
	select_index(scene, key);
	translate(scene, scene->selected, key);
	modify_dim(scene, scene->selected, key);
	update_material(scene, scene->selected, key);
	rotate(scene, scene->selected, key);
	return (0);
}

void	launch_window_hook(t_scene *scene)
{
	t_backup	*backup;

	backup = create_backup(scene);
	mlx_hook(scene->mlx->win, 17, 0, hook_exit, backup);
	mlx_key_hook(scene->mlx->win, hook_keypress, backup);
	mlx_hook(scene->mlx->win, 04, (1L << 2), hook_mousepress, backup->scene);
	mlx_hook(scene->mlx->win, 05, (1L << 3), hook_mouserelease, backup->scene);
	mlx_hook(scene->mlx->win, 06, (1L << 6), hook_mousemove, backup->scene);
	mlx_loop(scene->mlx->mlx);
}
