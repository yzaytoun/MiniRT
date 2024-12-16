/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar_eq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:15:05 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 15:51:35 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	rgb(int red, int green, int blue)
{
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	return (red << 16 | green << 8 | blue);
}

double	p_dist(t_point2D a, t_point2D b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

// Switch bar equation.
int	bar_value(void *control, int x, int y, int progress)
{
	t_control	*c;
	t_point2D	pos;
	int			color;
	double		r;

	c = (t_control *)control;
	if (progress > 100)
		progress = 100;
	pos.x = (int)(100 * x / c->dim.x);
	pos.y = (int)(100 * y / c->dim.y);
	r = c->dim.y * 0.5;
	if (p_dist((t_point2D){x, y},
		(t_point2D){(progress * c->dim.x) / 100, r}) < r)
		color = 90 << 16 | 30 << 8 | 230;
	else if (pos.y >= 40 && pos.y <= 60)
		color = 83 << 16 | 71 << 8 | 172;
	else
		color = 0xFF000000;
	return (color);
}
