/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:31:49 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/14 20:21:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

t_generic	*create_ambient(char **in)
{
	t_generic		*ambient;
	t_dimensions	*dim;

	if (ft_sarrsize(in) != 4)
		printerror("Error on ambient inputs");
	dim = new_dimension();
	dim->bright = ft_atod(in[0]);
	if (dim->bright > 1)
		printerror("Error on ambient brightness");
	ambient = new_element(AMBIENT);
	ambient->material.color
		= create_color(ft_atoi(in[1]), ft_atoi(in[2]), ft_atoi(in[3]));
	ambient->material.color.a = color_alpha(ambient->material.color);
	if (isvalid_color(ambient->material.color) == FALSE)
		printerror("Error on ambient color");
	ambient->dim = dim;
	return (ambient);
}

t_generic	*create_camera(char	**in)
{
	t_camera	*cam;
	t_generic	*camera;

	if (ft_sarrsize(in) != 7)
		printerror("Error on camera inputs");
	cam = ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		return (NULL);
	cam->vfield = to_radian(21);
	cam->hfield = to_radian(ft_atoi(in[6]));
	cam->focal = 1;
	camera = new_element(CAMERA);
	camera->center = create_point(
			ft_atod(in[0]), ft_atod(in[1]), ft_atod(in[2]));
	cam->dir = normalize(
			create_point(ft_atod(in[3]), ft_atod(in[4]), ft_atod(in[5])));
	if (!normal_check(cam->dir))
		printerror("Error on camera vector");
	cam->orientation = (t_point){0};
	get_vector_angles(cam->dir, &cam->orientation.x, &cam->orientation.z);
	cam->orientation.z -= M_PI_2;
	camera->dim = cam;
	add_camera_viewport(camera);
	return (camera);
}

t_generic	*create_light(char **in)
{
	t_generic		*light;
	t_dimensions	*dim;

	if (ft_sarrsize(in) != 7)
		printerror("Error on camera inputs");
	dim = new_dimension();
	dim->bright = ft_atod(in[3]);
	if (dim->bright > 1)
		printerror("Error on light brightness");
	light = create_element(LIGHT, in, dim);
	light->material.color = create_color(
			ft_atoi(in[4]), ft_atoi(in[5]), ft_atoi(in[6]));
	if (isvalid_color(light->material.color) == FALSE)
		printerror("Error on light color");
	light->material.color.a = color_alpha(light->material.color);
	return (light);
}
