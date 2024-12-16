/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_logger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:07:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/25 16:04:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_elementtype(t_elementtype type)
{
	if (type == AMBIENT)
		ft_putstr_fd("Element: AMBIENT\n", STDOUT_FILENO);
	else if (type == CAMERA)
		ft_putstr_fd("Element: CAMERA\n", STDOUT_FILENO);
	else if (type == LIGHT)
		ft_putstr_fd("Element: LIGHT\n", STDOUT_FILENO);
	else if (type == PLANE)
		ft_putstr_fd("Element: PLANE\n", STDOUT_FILENO);
	else if (type == SPHERE)
		ft_putstr_fd("Element: SPHERE\n", STDOUT_FILENO);
	else if (type == CYLINDER)
		ft_putstr_fd("Element: CYLINDER\n", STDOUT_FILENO);
	else if (type == CONE)
		ft_putstr_fd("Element: CONE\n", STDOUT_FILENO);
}

void	printelements(t_parser parser)
{
	t_list	*node;
	t_input	*in;

	node = parser.elements;
	ft_putendl_fd("Elements list:", STDOUT_FILENO);
	ft_putendl_fd("-------------------------\n", STDOUT_FILENO);
	while (node != NULL)
	{
		in = (t_input *)node->content;
		ft_putstr_fd("Type = ", STDOUT_FILENO);
		print_elementtype(in->type);
		ft_sarrprint(in->inputs);
		ft_putstr_fd("\n ----------------- \n", STDOUT_FILENO);
		node = node->next;
	}
}

void	generic_bbox_log(t_generic *generic)
{
	int	index;

	index = -1;
	if (generic)
	{
		ft_putstr_fd("\t", STDOUT_FILENO);
		print_point("bbmax -> ", generic->bbox.bbmax);
		ft_putstr_fd("\t", STDOUT_FILENO);
		print_point("bbmin -> ", generic->bbox.bbmin);
		while (++index < VERTICES_NUM)
		{
			ft_putstr_fd("\tVertix", STDOUT_FILENO);
			ft_putnbr_fd(index, STDOUT_FILENO);
			ft_putstr_fd("-> ", STDOUT_FILENO);
			print_point(NULL, generic->bbox.vertices[index]);
		}
	}
}

void	generic_log(t_generic *generic, t_bool show_bbox)
{
	if (generic)
	{
		ft_putendl_fd(
			"\n|--------------- Element LOG -----------------|\n",
			STDOUT_FILENO);
		ft_putstr_fd("ID: ", STDOUT_FILENO);
		ft_putnbr_fd(generic->id, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		print_elementtype(generic->type);
		print_point("Center", generic->center);
		if (generic->dim)
			dimensions_log(generic->dim, generic->type);
		if (show_bbox == TRUE)
			generic_bbox_log(generic);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void	ray_log(t_ray ray, double t)
{
	ft_putendl_fd("\n|------------- Ray LOG -------------------|\n",
		STDOUT_FILENO);
	print_point("origin: ", ray.origin);
	print_point("dir: ", ray.dir);
	print_point("at: ", ray.at(ray, t));
	ft_putstr_fd("from: ", STDOUT_FILENO);
	generic_log(ray.from, TRUE);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
