/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_material_sets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:20:32 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/22 19:31:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

/*
    Elimina el uso de materiales procedurales y
		muestra el menu de colores.
*/
void	set_color(t_control *control)
{
	t_scene	*scene;
	t_menu	*menu_rgb;
	t_pbar	*bar;

	scene = (t_scene *)control->data;
	if (!scene->selected)
		return ;
	clear_material(&scene->selected->material, scene->mlx->mlx);
	render(scene);
	scene->target_color = &scene->selected->material.color;
	menu_rgb = scene->mnx.get(&scene->mnx, MENU_RGB);
	menu_rgb->visible = !menu_rgb->visible;
	bar = (t_pbar *)mnx_get_control(menu_rgb->controls.list, 0)->bar;
	bar->progress = scene->target_color->r * 100.0 / 255.0;
	bar = (t_pbar *)mnx_get_control(menu_rgb->controls.list, 1)->bar;
	bar->progress = scene->target_color->g * 100.0 / 255.0;
	bar = (t_pbar *)mnx_get_control(menu_rgb->controls.list, 2)->bar;
	bar->progress = scene->target_color->b * 100.0 / 255.0;
	mnx_img_to_img(&scene->mnx.img, &scene->mlx->img, (t_point2D){0, 0});
	scene->mnx.draw(&scene->mnx);
}

void	set_buttons_color(t_menu *menu_chkr, t_ckrparam *params)
{
	t_control	*button;

	if (!params)
		return ;
	button = mnx_get_control(menu_chkr->controls.list, 2);
	img_iter_context(&button->img, &params->acolor, round_background);
	button = mnx_get_control(menu_chkr->controls.list, 3);
	img_iter_context(&button->img, &params->bcolor, round_background);
}

/*
    Asigna/Resetea el material checkerboard procedural.
*/
void	set_checker(t_control *control)
{
	t_scene	*scene;
	t_menu	*menu_chkr;

	scene = (t_scene *)control->data;
	if (!scene->selected)
		return ;
	if (scene->selected->material.paramtype != CHECKER)
	{
		add_mat_ckrparam(&scene->selected->material, scene->mlx->mlx);
		scene->selected->material.paramtype = CHECKER;
		scene->selected->material.procedure = checkerboard2;
		render(scene);
	}
	menu_chkr = scene->mnx.get(&scene->mnx, MENU_CHKR);
	set_buttons_color(menu_chkr,
		(t_ckrparam *)scene->selected->material.params);
	menu_chkr->visible = !menu_chkr->visible;
	mnx_img_to_img(&scene->mnx.img, &scene->mlx->img, (t_point2D){0, 0});
	scene->mnx.draw(&scene->mnx);
}
