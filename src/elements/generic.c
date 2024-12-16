/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:45:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/22 20:03:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_generic	*create_element(t_elementtype type, char **in, void *dim)
{
	t_generic	*element;

	element = new_element(type);
	element->center = create_point(
			ft_atod(in[0]), ft_atod(in[1]), ft_atod(in[2]));
	element->normal = normalize(
			create_point(ft_atod(in[3]), ft_atod(in[4]), ft_atod(in[5])));
	element->dim = dim;
	element->material.nmap.ptr = NULL;
	element->material.pnmap = NULL;
	element->material.procedure = NULL;
	return (element);
}

void	delete_generic(void *content)
{
	t_generic	*generic;

	if (content == NULL)
		return ;
	generic = (t_generic *)content;
	if (generic->dim != NULL)
		free(generic->dim);
	free(generic);
	generic = NULL;
}

void	*copy_generic(void *content)
{
	t_generic	*copy;
	t_generic	*generic;

	if (content == NULL)
		return (NULL);
	generic = (t_generic *)content;
	copy = new_element(generic->type);
	copy->id = generic->id;
	copy->center = generic->center;
	copy->normal = generic->normal;
	copy->material = generic->material;
	copy->dim = copy_dimensions(generic->dim, generic->type);
	copy->bbox = generic->bbox;
	return (copy);
}

t_dimensions	*new_dimension(void)
{
	t_dimensions	*dim;

	dim = malloc(sizeof(t_dimensions));
	if (dim == NULL)
		return (NULL);
	ft_bzero(dim, sizeof(t_dimensions));
	return (dim);
}

void	*copy_dimensions(void *dim, t_elementtype type)
{
	void	*dim_copy;

	dim_copy = NULL;
	if (type == CAMERA)
		dim_copy = copy_camera_dimensions((t_camera *)dim);
	else
		dim_copy = copy_geometry_dimensions((t_dimensions *)dim);
	return (dim_copy);
}
