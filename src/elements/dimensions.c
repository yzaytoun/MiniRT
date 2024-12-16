/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c 	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:20:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/07 18:04:42 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_dimensions	*copy_geometry_dimensions(t_dimensions *dim)
{
	t_dimensions	*dim_copy;

	dim_copy = NULL;
	if (dim == NULL)
		return (NULL);
	dim_copy = new_dimension();
	dim_copy->bright = dim->bright;
	dim_copy->diameter = dim->diameter;
	dim_copy->ratio = dim->ratio;
	dim_copy->height = dim->height;
	return (dim_copy);
}

t_camera	*copy_camera_dimensions(t_camera *cam)
{
	t_camera	*cam_copy;

	cam_copy = NULL;
	if (cam == NULL)
		return (NULL);
	cam_copy = malloc(sizeof(t_camera));
	if (cam_copy == NULL)
		return (NULL);
	cam_copy->dir = cam->dir;
	cam_copy->hfield = cam->hfield;
	cam_copy->vfield = cam->vfield;
	cam_copy->look_at = cam->look_at;
	cam_copy->vp = cam->vp;
	cam_copy->orientation = cam->orientation;
	cam_copy->new_look_at = cam->new_look_at;
	cam_copy->focal = cam->focal;
	return (cam_copy);
}

void	dimensions_log(t_dimensions *dim, t_elementtype type)
{
	if (dim)
	{
		ft_putstr_fd("\n|--- Dimensions: \n", STDOUT_FILENO);
		if (type == LIGHT)
		{
			ft_putstr_fd("Bright: ", STDOUT_FILENO);
			ft_putdbl_fd(dim->bright, 5, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		if (type == CYLINDER || type == SPHERE || type == CONE)
		{
			ft_putstr_fd("Diameter: ", STDOUT_FILENO);
			ft_putdbl_fd(dim->diameter, 5, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			ft_putstr_fd("Height: ", STDOUT_FILENO);
			ft_putdbl_fd(dim->height, 5, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		if (type == CONE)
		{
			ft_putstr_fd("Ratio: ", STDOUT_FILENO);
			ft_putdbl_fd(dim->ratio, 5, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
	}
}
