/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:30:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 15:07:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// Función para calcular el ángulo en radianes entre
// un vector y el vector (0, 0, 1) en el plano XZ
double	angle_xz(t_point v)
{
	const double	len = sqrt(v.x * v.x + v.z * v.z);

	if (len == 0)
		return (0.0);
	return (acos(v.z / len));
}

// Función para calcular el ángulo en radianes entre
//  un vector y el vector (0, 0, 1) en el plano YZ
double	angle_yz(t_point v)
{
	const double	len = sqrt(v.y * v.y + v.z * v.z);

	if (len == 0)
		return (0.0);
	return (acos(v.z / len));
}
