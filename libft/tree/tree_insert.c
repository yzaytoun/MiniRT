/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:44:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/16 20:23:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tree_insert(t_tree **root, void *data, t_tree_nodepos nodepos)
{
	if (root != NULL)
	{
		if (nodepos == CENTER || (*root) == NULL)
			(*root) = tree_new_node(data);
		else if (nodepos == LEFT && (*root) != NULL)
			(*root)->left = tree_new_node(data);
		else if (nodepos == RIGHT && (*root) != NULL)
			(*root)->right = tree_new_node(data);
	}
}
