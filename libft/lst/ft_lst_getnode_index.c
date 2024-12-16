/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getnode_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:14:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/18 11:48:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	@param compare_option=0 Compares content pointers
	@param compare_option=1 Compares node pointers
	@return Node index if pointers are the same else -1
*/
int	ft_lst_getnode_index(t_list *lst, void *ptr_to_find, int compare_option)
{
	t_list	*node;
	int		index;

	if (lst == NULL || ptr_to_find == NULL
		|| (compare_option != 1 && compare_option != 0))
		return (-1);
	node = lst;
	index = 0;
	while (node != NULL)
	{
		if (compare_option == 1)
		{
			if (node == ptr_to_find)
				return (index);
		}
		else if (compare_option == 0)
			if (node->content == ptr_to_find)
				return (index);
		node = node->next;
		++index;
	}
	return (-1);
}
