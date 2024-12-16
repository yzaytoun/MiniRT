/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:35:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/05/05 14:36:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point	normalize(t_point vector)
{
	const double	len = vector_length(vector);

	if (len == 1)
		return (vector);
	else if (len)
		return (vector_multiply(vector, 1.0 / len));
	else
		return (vector);
}

void	restrict_double(double *var, double val_min, double val_max)
{
	if (*var < val_min)
		*var = val_min;
	else if (*var > val_max)
		*var = val_max;
}

double	distance(t_point p1, t_point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2)
			+ pow(p2.y - p1.y, 2)
			+ pow(p2.z - p1.z, 2)));
}

t_point	invert(t_point vector)
{
	return (vector_multiply(vector, -1));
}

t_point	vec_to_radian(t_point angle_val)
{
	t_point	angle_rad;

	angle_rad.x = to_radian(angle_val.x);
	angle_rad.y = to_radian(angle_val.y);
	angle_rad.z = to_radian(angle_val.z);
	return (angle_rad);
}
