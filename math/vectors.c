/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:59:50 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 14:58:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_point	reflect_onplane(t_point incident, t_point normal)
{
	const t_point	nincident = normalize(incident);
	const t_point	nnormal = normalize(normal);
	const double	dot = 2 * dot_product(nincident, nnormal);
	t_point			reflection;

	reflection = vectors_res(nincident, vector_multiply(nnormal, dot));
	return (normalize(reflection));
}

t_point	to_first_octant(t_point vector)
{
	return (vector_multiply(
			vectors_sum_escalar(normalize(vector), 1.0), 0.5));
}

double	projection_length(t_point v, t_point u)
{
	return (vector_length(
			vector_multiply(v, dot_product(v, u) / dot_product(v, v))));
}

t_point	vectors_res_escalar(t_point a, double val)
{
	t_point	point;

	point.x = a.x - val;
	point.y = a.y - val;
	point.z = a.z - val;
	return (point);
}

void	print_vector(char *str, t_point o, t_point d)
{
	printf("%s = vector((%f, %f, %f), (%f, %f, %f))\n",
		str, o.x, o.y, o.z, d.x, d.y, d.z);
}
