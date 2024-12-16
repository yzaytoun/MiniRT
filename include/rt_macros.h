/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:11:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 10:09:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MACROS_H
# define RT_MACROS_H

/* Window Dimensions */
# define WIN_W	    	800
# define WIN_H			800
# define WIN_D			400
# define BOUNCE_LIMIT 	3
# define OBJ_LIMIT		1000
# define T_MIN			0.0001
# define ROT_ANGLE		2

# define XK_MISCELLANY
# define XK_XKB_KEYS
# define XK_LATIN1

# include "X11/keysymdef.h"

# ifdef LINUX
/* Mouse Buttons */
#  define M_LEFT  	1
#  define M_RIGHT 	3
#  define M_DRAG 	2
#  define M_WUP 	4
#  define M_WDO 	5
# endif

# ifndef LINUX
/* Mouse Buttons */
#  define M_LEFT 	1
#  define M_RIGHT	2
#  define M_DRAG	3
#  define M_WUP		4
#  define M_WDO		5
# endif

/* Colores */
# define MENU_COLOR		  83
# define WHITE 	    0xFFFFFF
# define BLACK 	    0x000000
# define BLUE 	    0x0000FF
# define GREEN 	    0x00FF00
# define RED 	    0xFF0000
# define GREY 	    0x888888
# define DARK_BLUE  0x000088
# define DARK_GREEN 0x008800
# define DARK_RED   0x880000

/* STRUCTs */
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif