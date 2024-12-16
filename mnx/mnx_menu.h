/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnx_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:49:01 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/07 14:53:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNX_MENU_H
# define MNX_MENU_H

# ifdef MLX_MENU
#  define M_LEFT	1
#  define M_RIGHT	2
#  define M_DRAG	3
#  define M_WUP		4
#  define M_WDO		5
# endif

# define M_DRAGING	0b001010

# define C_WHITE	0xFFFFFF
# define C_RED		0xFF0000
# define C_GREEN	0xFF00
# define C_BLUE		0xFF

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "mnx_struct.h"
# include "mlx_struct.h"

t_mnx			mnx_innit(void *mlx, void *win, int win_width, int win_height);

t_control		*mnx_control_create(t_menu *menu, int dim_x, int dim_y);
void			mnx_control_delete(t_menu *menu, int index);
t_control		*mnx_get_control(t_list *controls, int idx);

int				mnx_control_drag(t_menu *menu, t_control *ctrl, int x, int y);
int				mnx_button_drag(t_menu *menu, t_control *button, int x, int y);
int				mnx_pbar_drag(t_menu *menu, t_control *bar, int x, int y);

t_menu			*mnx_create_menu(void *mlx, void *win);
void			mnx_menu_draw(void *data);
void			mnx_menu_clean(t_menu *menu);

void			mnx_hook_mouseup(int button, t_control *ctrl);
void			mnx_hook_mousedown(int button, int x, int y, t_control *ctrl);

void			mnx_img_to_img(t_mlximg *end, t_mlximg *wr, t_point2D pos);
void			my_mlx_pixel_put(t_mlximg *img, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_mlximg img, int x, int y);

t_mlximg		mnx_img_new(void *mlx, int width, int height);
void			matrix_clear(t_control ***matrix, int win_w, int win_h);

/** Mnx Free **/
void			mnx_destroy(t_mnx *mnx);
void			mnx_control_del(void *data);

#endif
