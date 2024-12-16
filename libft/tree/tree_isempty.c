/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_isempty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:46:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/15 16:46:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Check if tree is empty
	If root is empty it returns 1
	else 0
*/
int	tree_isempty(t_tree *root)
{
	if (root == NULL || root->data == NULL)
		return (1);
	return (0);
}
