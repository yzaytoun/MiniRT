/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:00:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 15:01:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	sum_color(t_color a, t_color b)
{
	int	color[3];
	int	i;

	color[0] = a.r + b.r;
	color[1] = a.g + b.g;
	color[2] = a.b + b.b;
	i = -1;
	while (++i < 3)
		if (color[i] > 255)
			color[i] = 255;
	return (create_color(color[0], color[1], color[2]));
}

double	color_alpha(t_color color)
{
	double	max;

	max = color.r;
	if (color.g > max)
		max = color.g;
	if (color.b > max)
		max = color.b;
	return (max / 255);
}

int	color_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
