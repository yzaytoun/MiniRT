/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 15:01:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	mix_color(t_color a, t_color b, double factor)
{
	t_color	color;

	if (factor > 1)
		factor = 1;
	if (factor < 0)
		factor = 0;
	color.r = a.r * (1.0 - factor) + b.r * factor;
	color.g = a.g * (1.0 - factor) + b.g * factor;
	color.b = a.b * (1.0 - factor) + b.b * factor;
	return (color);
}

t_color	color_at(t_mlximg img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= img.width || y < 0 || y >= img.height)
		return (create_color(0, 0, 255));
	dst = img.addr + ((y) * img.line_length
			+ (x) * (img.bits_per_pixel / 8));
	return (int_to_color(*(unsigned int *)dst));
}
