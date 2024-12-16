/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octreeiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:43:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/30 19:47:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "octree.h"

/* Childs iterators*/

/*
	@brief Iterate Octree child nodes
*/
void	octreeiter(t_octree *node, void (*f)(t_octree *))
{
	int	index;

	index = -1;
	if (node == NULL || f == NULL)
		return ;
	f(node);
	while (++index < CHILDS_NUM)
		octreeiter(node->childnode[index], f);
}

/*
	@brief Iterate Octree child nodes content
*/
void	octreeiter_context(
	t_octree *node, void (*f)(t_octree *, void *context), void *context)
{
	int	index;

	index = -1;
	if (node == NULL || f == NULL)
		return ;
	f(node, context);
	while (++index < CHILDS_NUM)
		octreeiter_context(node->childnode[index], f, context);
}

/* Neighbours iterators*/

/*
	@brief Iterate Octree child nodes neighbours
*/
void	octreeiter_neighbours(t_octree *node, void (*f)(t_octree *))
{
	int	index;

	index = -1;
	if (node == NULL || f == NULL)
		return ;
	while (++index < NEIGHBOURS_NUM)
		octreeiter_neighbours(node->neighbour[index], f);
}

/*
	@brief Iterate Octree child nodes neighbours content
*/
void	octreeiter_neighbours_context(
	t_octree *node, void (*f)(t_octree *, void *context), void *context)
{
	int	index;

	index = -1;
	if (node == NULL || f == NULL)
		return ;
	while (++index < NEIGHBOURS_NUM)
		octreeiter_neighbours_context(node->neighbour[index], f, context);
}

/*
	@brief Iterate Octree child nodes without
		applying function to parent root
*/
void	octreeiter_childnodes(t_octree *node, void (*f)(t_octree *))
{
	int	index;

	index = -1;
	if (node == NULL || f == NULL)
		return ;
	while (++index < CHILDS_NUM)
		octreeiter_childnodes(node->childnode[index], f);
}
