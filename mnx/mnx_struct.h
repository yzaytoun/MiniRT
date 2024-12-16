/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:09:19 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 15:45:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNX_STRUCT_H
# define MNX_STRUCT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "mlx_struct.h"

typedef struct s_mnx		t_mnx;
typedef struct s_menu		t_menu;
typedef struct s_control	t_control;

typedef struct s_point2D
{
	int	x;
	int	y;
}	t_point2D;

typedef struct s_snap
{
	t_point2D		grid[25][25];
	t_point2D		pos;
	t_point2D		sep;
	t_point2D		dim;
}	t_snap;

typedef struct s_pbar
{
	int			(*draw_eq)(void *data, int pixel_x, int pixel_y, int progress);
	void		(*on_change)(t_control *data);
	int			progress;
}	t_pbar;

typedef struct s_label
{
	t_point2D	pos;
	char		*text;
	int			color;
}	t_label;

struct s_control
{
	int			idx;
	t_point2D	pos;
	t_point2D	dim;
	t_mlximg	img;
	int			dragable;
	void		(*on_click)(t_control *ctrl);
	void		(*on_hover)(void *data);
	void		*data;
	void		*bar;
	t_label		*label;
	t_menu		*menu;
};

typedef struct s_controls
{
	int			count;
	t_list		*list;
	t_control	*(*add)(t_menu *menu, int dim_x, int dim_y);
	void		(*del)(t_menu *menu, int index);
}	t_controls;

typedef struct s_event
{
	t_point2D	pos;
	int			button;
	void		*origin;
}	t_event;

struct s_menu
{
	void		*data;
	void		*mlx;
	void		*win;
	t_mlximg	img;
	t_mlximg	background;
	t_controls	controls;
	int			events;
	t_control	*selected;
	int			dragable;
	int			visible;
	t_snap		snap;
	t_point2D	mouse;
	t_point2D	pos;
	t_control	**(*matrix);
};

struct s_mnx
{
	void		*mlx;
	void		*win;
	t_mlximg	img;
	int			events;
	int			win_height;
	int			win_width;
	t_control	**(*matrix);
	t_control	*hover_on;
	t_list		*mnx_lst;
	void		(*add)(t_mnx *mnx, t_menu *menu);
	t_menu		*(*get)(t_mnx *mnx, int index);
	void		(*draw)(t_mnx *mnx);
};

#endif