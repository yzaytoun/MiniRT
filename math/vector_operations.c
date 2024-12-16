/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/19 15:22:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point	vector_multiply(t_point a, double val)
{
	t_point	point;

	point.x = a.x * val;
	point.y = a.y * val;
	point.z = a.z * val;
	return (point);
}

t_point	vectors_sum(t_point a, t_point b)
{
	t_point	point;

	point.x = a.x + b.x;
	point.y = a.y + b.y;
	point.z = a.z + b.z;
	return (point);
}

t_point	vectors_sum_escalar(t_point a, double val)
{
	t_point	point;

	point.x = a.x + val;
	point.y = a.y + val;
	point.z = a.z + val;
	return (point);
}

/* Return the vector a - b */
t_point	vectors_res(t_point a, t_point b)
{
	t_point	point;

	point.x = a.x - b.x;
	point.y = a.y - b.y;
	point.z = a.z - b.z;
	return (point);
}

t_point	vectors_divide(t_point a, t_point b)
{
	t_point	point;

	point.x = a.x / b.x;
	point.y = a.y / b.y;
	point.z = a.z / b.z;
	return (point);
}
