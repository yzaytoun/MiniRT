/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:06:12 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/26 11:52:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "rt_struct.h"
# include "mlx_struct.h"
# include "mnx_struct.h"
# include "scene.h"

enum e_menu
{
	MENU_UBAR,
	MENU_MAT,
	MENU_OPC,
	MENU_CHKR,
	MENU_RGB,
};

enum e_opc
{
	BAR_BOUNCES,
	BAR_RED,
	BAR_GREEN,
	BAR_BLUE,
};

/* Menus */
void		create_menus(t_scene *scene);
t_menu		*create_menu_rgb(t_scene *scene);
t_menu		*create_menu_material(t_scene *scene);
t_menu		*create_menu_options(t_scene *scene);
t_menu		*create_menu_upperbar(t_scene *scene);
t_menu		*create_menu_checker(t_scene *scene);

/* Buttons Actions */
void		add_button_close(t_scene *scene, t_menu *menu,
				int pos_x, int pos_y);
// 
void		set_checker(t_control *control);
void		set_param(t_control *control, int idx, double range);
void		set_color(t_control *control);

/* Img */
void		button_close_shape(t_mlximg *img, int x, int y);
void		round_background(t_mlximg *img, void *data, int x, int y);

/* Control */
t_control	*innit_bar(t_menu *menu, int pos_x,
				int pos_y, void (*change_fn)(t_control *data));
t_control	*innit_button(t_menu *menu, int pos_x, int pos_y,
				void (*on_click)(t_control *data));
t_control	*innit_img_button(t_menu *menu, char *dir, t_point2D pos,
				void (*on_click)(t_control *data));
void		add_label(t_control *ctrl, char *text, t_point2D pos, int color);

/* Color Menu */
void		bar_set_red(t_control *control);
void		bar_set_green(t_control *control);
void		bar_set_blue(t_control *control);

/* Checker Menu */
void		bar_set_xsize(t_control *control);
void		bar_set_ysize(t_control *control);
void		bar_set_acolor(t_control *control);
void		bar_set_bcolor(t_control *control);
void		bar_set_param(t_scene *scene, t_ckrparam *p, t_pbar *bar, int var);
void		bar_get_var(t_control *control, int var);

/* Options Menu */
void		bar_set_alight_red(t_control *control);
void		bar_set_alight_green(t_control *control);
void		bar_set_alight_blue(t_control *control);
void		bar_set_alight_color(t_control *control, t_bool r,
				t_bool g, t_bool b);

#endif