/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:01:21 by jvasquez          #+#    #+#             */
/*   Updated: 2024/06/02 20:44:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

t_generic	*create_sphere(char **in)
{
	t_generic		*sphere;
	t_dimensions	*dim;

	if (ft_sarrsize(in) != 7)
		printerror("Error on sphere inputs");
	dim = new_dimension();
	dim->diameter = ft_atod(in[3]);
	sphere = create_element(SPHERE, in, dim);
	sphere->material.color = create_color(
			ft_atoi(in[4]), ft_atoi(in[5]), ft_atoi(in[6]));
	if (isvalid_color(sphere->material.color) == FALSE)
		printerror("Error on sphere color");
	sphere->material.reflx = 1;
	sphere->material.rough = 1;
	return (sphere);
}

t_generic	*create_plane(char **in)
{
	t_generic	*plane;

	if (ft_sarrsize(in) != 9)
		printerror("Error on plane inputs");
	plane = create_element(PLANE, in, NULL);
	if (!normal_check(plane->normal))
		printerror("Error on plane normal");
	plane->material.color = create_color(
			ft_atoi(in[6]), ft_atoi(in[7]), ft_atoi(in[8]));
	if (isvalid_color(plane->material.color) == FALSE)
		printerror("Error on plane color");
	plane->material.reflx = 1;
	plane->material.rough = 1;
	return (plane);
}

t_generic	*create_cylinder(char **in)
{
	t_dimensions	*dim;
	t_generic		*cylinder;

	if (ft_sarrsize(in) != 11)
		printerror("Error on cylinder inputs");
	dim = new_dimension();
	dim->diameter = ft_atod(in[6]);
	dim->height = ft_atod(in[7]);
	cylinder = create_element(CYLINDER, in, dim);
	if (!normal_check(cylinder->normal))
		printerror("Error on cylinder normal");
	cylinder->material.color = create_color(
			ft_atoi(in[8]), ft_atoi(in[9]), ft_atoi(in[10]));
	if (isvalid_color(cylinder->material.color) == FALSE)
		printerror("Error on cylinder color");
	cylinder->material.reflx = 1;
	cylinder->material.rough = 1;
	return (cylinder);
}

t_generic	*create_cone(char **in)
{
	t_generic		*cone;
	t_dimensions	*dim;

	if (ft_sarrsize(in) != 11)
		printerror("Error on cone inputs");
	dim = new_dimension();
	dim->diameter = ft_atod(in[6]);
	dim->height = ft_atod(in[7]);
	cone = create_element(CONE, in, dim);
	if (!normal_check(cone->normal))
		printerror("Error on cone normal");
	cone->material.color = create_color(
			ft_atoi(in[8]), ft_atoi(in[9]), ft_atoi(in[10]));
	if (isvalid_color(cone->material.color) == FALSE)
		printerror("Error on cone color");
	cone->material.reflx = 0;
	cone->material.rough = 1;
	return (cone);
}
