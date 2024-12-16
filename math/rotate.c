/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:42:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 15:08:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"
#include "rt.h"

void	rotate_vector(t_point *vector, double angle_rad, t_axis axis)
{
	double	var[2];

	if (axis == X_AXIS)
	{
		var[0] = vector->y;
		var[1] = vector->z;
		vector->y = var[0] * cos(angle_rad) - var[1] * sin(angle_rad);
		vector->z = var[0] * sin(angle_rad) + var[1] * cos(angle_rad);
	}
	else if (axis == Y_AXIS)
	{
		var[0] = vector->x;
		var[1] = vector->z;
		vector->x = var[0] * cos(angle_rad) + var[1] * sin(angle_rad);
		vector->z = -var[0] * sin(angle_rad) + var[1] * cos(angle_rad);
	}
	else if (axis == Z_AXIS)
	{
		var[0] = vector->x;
		var[1] = vector->y;
		vector->x = var[0] * cos(angle_rad) - var[1] * sin(angle_rad);
		vector->y = var[0] * sin(angle_rad) + var[1] * cos(angle_rad);
	}
}

double	to_radian(double angle)
{
	return ((angle * M_PI) / 180.0f);
}

double	to_degrees(double angle)
{
	return ((int)((angle * 180.0f) / M_PI) % 360);
}
