/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:45:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/22 19:37:29 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "parser.h"
# include "mlx.h"
# include "rt_macros.h"
# include "mnx_struct.h"
# include "rt_math.h"
# include "octree.h"
# ifdef LINUX
#  include "mlx_int.h"
# endif

typedef enum e_param				t_param;
typedef struct s_ray				t_ray;
typedef struct s_camera				t_camera;
typedef struct s_viewport			t_viewport;
typedef struct s_dimensions			t_dimensions;
typedef struct s_generic			t_generic;
typedef struct s_mouse				t_mouse;
typedef struct s_mlx				t_mlx;
typedef struct s_color				t_color;
typedef struct s_material			t_material;
typedef struct s_geomatrix			t_geomatrix;
typedef struct s_octree_navigator	t_octreenav;

enum e_param
{
	NONE,
	CHECKER,
	IMAGE
};

typedef enum e_updatekey
{
	ROTATE = 1,
	TRANSLATE,
	DIVIDE,
	MULTI,
	SUB,
	SUM,
	ZOOM,
	DIR,
	UP,
	STANDER,
	OCTREE_BASED,
	ROOT_NODE,
	LAST_NODE,
	CAM_NODE
}	t_updatekey;

struct s_color
{
	double	a;
	int		r;
	int		g;
	int		b;
};

typedef struct s_ckrparam
{
	int		xsize;
	int		ysize;
	int		xstart;
	int		lwidth;
	int		lcolor;
	t_color	acolor;
	t_color	bcolor;
}			t_ckrparam;

/*
	x_scale, y_scale, persistence (0-1),
	octaves (0-8), frequency, amplitude.
*/
typedef struct s_perlparam
{
	double	x_scale;
	double	y_scale;
	double	persistence;
	double	octaves;
	double	frequency;
	double	amplitude;
}			t_perlparam;

struct s_mouse
{
	t_bool		left;
	t_bool		right;
	t_bool		middle;
	t_point		buttonpress;
	t_point		buttonrelease;
	t_point		position;
};

struct s_mlx
{
	void		*mlx;
	void		*win;
	t_mlximg	img;
	t_mouse		mouse;
};

typedef struct s_material
{
	t_color		color;
	double		rough;
	double		reflx;
	t_mlximg	nmap;
	t_param		paramtype;
	void		*params;
	int			(*procedure)(void *param, double x, double y);
	t_point		(*pnmap)(void *param, double x, double y);
	t_mlximg	img;
}	t_material;

struct s_dimensions
{
	double			height;
	double			diameter;
	double			bright;
	double			ratio;
};

typedef struct s_intersect
{
	double			t;
	t_generic		*geom;
	t_point			point;
}	t_intersect;

struct s_viewport
{
	double			height;
	double			width;
	double			dau;
	double			dav;
	t_point			upper_left;
	t_point			u;
	t_point			v;
	t_point			du;
	t_point			dv;
	t_point			pixel0;
	t_point			vup;
	t_point			right;
};

struct s_camera
{
	t_point		dir;
	t_point		look_at;
	t_point		new_look_at;
	t_point		right;
	double		hfield;
	double		vfield;
	t_viewport	vp;
	double		focal;
	t_point		orientation;
};

struct s_ray
{
	t_point		origin;
	t_point		dir;
	t_point		(*at)(t_ray ray, double t);
	t_generic	*from;
};

typedef struct s_calc
{
	t_ray			ray;
	t_intersect		front;
	t_color			color;
	t_color			lcolor;
	double			dot;
}	t_calc;

struct s_geomatrix
{
	t_generic	**(*matrix);
	int			nrows;
	int			ncolumns;
};

struct s_generic
{
	int				id;
	void			*dim;
	t_elementtype	type;
	t_point			center;
	t_point			normal;
	t_material		material;
	t_bbox			bbox;
	t_intersect		(*hit)(t_generic *, t_ray);
	t_point			(*normal_at)(t_generic *, t_point);
	void			(*get_bbox_boundaries)(t_generic *generic);
};

struct s_octree_navigator
{
	t_octree	(*root);
	t_octree	(*lastnode);
	t_octree	(*currnode);
	t_octree	(*camnode);
	t_generic	(*cam);
	void		(*moveto)(t_octreenav **, t_updatekey);
	t_updatekey	startfrom;
};

#endif