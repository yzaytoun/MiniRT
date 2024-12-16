/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:31:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/22 19:50:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/// @brief 		Si el material es procedural,
///					calcula el color usando la función, 
/// 			en caso contrario usa el color del objeto.
/// @param p 	Punto de intersección
/// @param geom Geometría intersectada
/// @return 	Color calculado
t_color	material_color(t_intersect inter)
{
	t_point		u;
	t_point		v;
	t_generic	*geom;
	t_point		uv;

	geom = inter.geom;
	uv = uv_at(inter.point, geom, &u, &v);
	if (geom->material.paramtype == IMAGE)
		return (color_at(geom->material.img, uv.x * geom->material.img.width,
				uv.y * geom->material.img.height));
	else if (geom->material.paramtype == CHECKER)
		return (int_to_color(geom->material.procedure(geom->material.params,
					uv.x * 100, uv.y * 100)));
	return (geom->material.color);
}

// TODO revisar el free de la imagen y llamar a destroy img.
void	clear_material(t_material *mat, void *mlx)
{
	if (!mlx)
		return ;
	if (mat->params)
	{
		free(mat->params);
		mat->params = NULL;
	}
	if (mat->img.ptr)
	{
		mlx_destroy_image(mlx, mat->img.ptr);
		mat->img.ptr = NULL;
	}
	if (mat->nmap.ptr)
	{
		mlx_destroy_image(mlx, mat->nmap.ptr);
		mat->nmap.ptr = NULL;
	}
	mat->procedure = NULL;
	mat->paramtype = NONE;
}

void	add_mat_ckrparam(t_material *mat, void *mlx)
{
	clear_material(mat, mlx);
	mat->params = malloc(sizeof(t_ckrparam));
	*(t_ckrparam *)mat->params = (t_ckrparam)
	{10, 10, 0, 0, GREY, create_color(0, 0, 0), create_color(255, 255, 255)};
	mat->paramtype = CHECKER;
}
