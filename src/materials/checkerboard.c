/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:09:44 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 17:44:22 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*void	checkerboard(void *data, t_mlximg *img, int x, int y)
{
	t_ckrparam	*params;
	int			color;

	params = (t_ckrparam *)data;
	if ((int)(y / params->ysize) % 2)
	{
		if (params->lwidth && (abs(y % params->ysize - params->ysize)
				<= params->lwidth || abs((x) % params->xsize - params->xsize)
				<= params->lwidth))
			color = params->lcolor;
		else
			color = (((int)(y / params->ysize) + (int)(x / params->xsize))
			% 2 == 0) ? color_int(params->acolor) : color_int(params->bcolor);
	}
	else
	{
		if (params->lwidth && (abs(y % params->ysize - params->ysize) <=
		params->lwidth || abs((x + params->xstart) % params->xsize
		- params->xsize) <= params->lwidth))
			color = params->lcolor;
		else
			color = (((int)(y / params->ysize) + (int)((x + params->xstart)
			/ params->xsize)) % 2 == 0) ? color_int(params->acolor) :
			color_int(params->bcolor);
	}
	my_mlx_pixel_put(img, x, y, color);
}*/

int	checkerboard2(void *data, double x, double y)
{
	t_ckrparam	*params;
	int			color;

	params = (t_ckrparam *)data;
	if ((int)(y / params->ysize) % 2)
	{
		if (((int)(y / params->ysize) + (int)(x / params->xsize)) % 2 == 0)
			color = color_int(params->acolor);
		else
			color = color_int(params->bcolor);
	}
	else
	{
		if (((int)(y / params->ysize) + (int)((x + params->xstart)
			/ params->xsize)) % 2 == 0)
			color = color_int(params->acolor);
		else
			color = color_int(params->bcolor);
	}
	return (color);
}
