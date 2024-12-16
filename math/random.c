/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:53:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/04/08 19:54:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point	random_vector(void)
{
	t_point		point;
	const int	n = INT_MAX * 0.5;

	point.x = rand() - n;
	point.y = rand() - n;
	point.z = rand() - n;
	return (normalize(point));
}

t_point	random_bounce(t_point vector)
{
	t_point	bounce;

	bounce = random_vector();
	while (dot_product(vector, bounce) <= 0)
		bounce = random_vector();
	return (bounce);
}
