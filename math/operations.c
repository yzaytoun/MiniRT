/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:44:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/10 20:39:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/* Al normalizar y multiplicar (dot) el valor queda entre -1 y 1
 se desplaza y normaliza de nuevo. */
double	norm_dot(t_point a, t_point b)
{
	return ((dot_product(normalize(a), normalize(b)) + 1) * 0.5);
}

/*
	@param vars[] (double[]) {low1, high1, low2, high2}
*/
double	remap(double value, double vars[])
{
	const double	low1 = vars[0];
	const double	high1 = vars[1];
	const double	low2 = vars[2];
	const double	high2 = vars[3];

	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}

t_point	cross_product(t_point a, t_point b)
{
	t_point	point;

	point.x = a.y * b.z - a.z * b.y;
	point.y = a.x * b.z - a.z * b.x;
	point.z = a.x * b.y - a.y * b.x;
	return (point);
}

double	vector_length(t_point vector)
{
	return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}
