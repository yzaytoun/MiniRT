/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octree_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:36:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 16:45:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_nodeloc(int type)
{
	if (type == LUB)
		ft_putstr_fd("location: LUB\n", STDOUT_FILENO);
	else if (type == RUB)
		ft_putstr_fd("location: RUB\n", STDOUT_FILENO);
	else if (type == LDB)
		ft_putstr_fd("location: LDB\n", STDOUT_FILENO);
	else if (type == RDB)
		ft_putstr_fd("location: RDB\n", STDOUT_FILENO);
	else if (type == LUF)
		ft_putstr_fd("location: LUF\n", STDOUT_FILENO);
	else if (type == RUF)
		ft_putstr_fd("location: RUF\n", STDOUT_FILENO);
	else if (type == LDF)
		ft_putstr_fd("location: LDF\n", STDOUT_FILENO);
	else if (type == RDF)
		ft_putstr_fd("location: RDF\n", STDOUT_FILENO);
	else if (type == PARENT)
		ft_putstr_fd("location: PARENT\n", STDOUT_FILENO);
}

static void	print_object(void *content)
{
	t_generic	*g;

	if (content == NULL)
	{
		ft_putstr_fd("** Empty **", STDOUT_FILENO);
		return ;
	}
	g = (t_generic *)content;
	if (g)
		generic_log(g, TRUE);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	octree_log(t_octree *root)
{
	if (root == NULL)
		return ;
	ft_putendl_fd(
		"\n---------------OCTREE NODE LOG-----------------",
		STDOUT_FILENO);
	print_nodeloc(root->nodeloc);
	print_point("bbmax: ", root->bbox.bbmax);
	print_point("bbmin: ", root->bbox.bbmin);
	printf("\n");
	printf("********* Objects ***********\n\n");
	if (root->objlist == NULL)
		ft_putendl_fd("** Empty **", STDOUT_FILENO);
	ft_lstiter(root->objlist, print_object);
}
