/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:59:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/16 17:59:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

// Permite calcular los angulos en coordenadas polares que forman dos puntos.
void	get_polar_angles(t_point c, t_point p, double *hangle, double *vangle)
{
	const double	dx = p.x - c.x;
	const double	dy = p.y - c.y;
	const double	dz = p.z - c.z;
	const double	r = sqrt(dx * dx + dy * dy + dz * dz);

	*vangle = acos(dz / r);
	*hangle = atan2(dy, dx);
}

// Permite calcular los angulos en coordenadas polares que forma un vector.
void	get_vector_angles(t_point v, double *hangle, double *vangle)
{
	*vangle = acos(v.z);
	*hangle = atan2(v.y, v.x);
}

// Permite calcular angulos con respecto a los ejes.
void	calculate_angles(t_point vector, t_point *angles)
{
	const t_point	u = normalize(vector);

	angles->x = acos(u.x);
	angles->y = acos(u.y);
	angles->z = acos(u.z);
}
