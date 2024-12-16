/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/17 17:12:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_point	create_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

/*
	@brief returns the mid point of the two vectors
*/
t_point	mid_point(t_point vector_1, t_point vector_2)
{
	return (
		vectors_divide(
			vectors_sum(vector_1, vector_2),
			(t_point){2, 2, 2})
		);
}

/*
	\brief Compare two points magnitude
	\return - 1 if vector_1 is bigger than vector_2
	\return - 0 if the two vectors are equal
	\return - 2 if vector_1 is smaller than vector_2
*/
int	vector_compare(t_point vector_1, t_point vector_2)
{
	const double	mag_vec1 = vector_length(vector_1);
	const double	mag_vec2 = vector_length(vector_2);

	if (mag_vec1 > mag_vec2)
		return (1);
	else if (mag_vec1 < mag_vec2)
		return (2);
	return (0);
}
