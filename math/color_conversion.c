/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/25 12:53:07 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/* Input vector must be normalized and pointing to first octant */
t_color	vector_to_color(t_point	vector)
{
	t_color	color;

	color.r = vector.x * 255;
	color.g = vector.y * 255;
	color.b = vector.z * 255;
	return (color);
}

/* Input vector must be normalized and pointing to first octant */
t_point	color_to_vector(t_color	color)
{
	t_point	vector;

	vector.x = color.r - 127.5;
	vector.y = 127.5 - color.g;
	vector.z = color.b;
	return (vector);
}

t_color	int_to_color(int c)
{
	t_color	color;

	color.r = (c >> 16) & 0b11111111;
	color.g = (c >> 8) & 0b11111111;
	color.b = c & 0b11111111;
	return (color);
}

void	modify_color(t_color *oldcolor, t_color newcolor)
{
	oldcolor->b = newcolor.b;
	oldcolor->g = newcolor.g;
	oldcolor->r = newcolor.r;
}
