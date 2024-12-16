/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/18 11:09:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	@brief Gets the first occurrence of content
	@return Node pointer where content is the found else NULL
	@note Compares void pointers without casting
*/
t_list	*ft_lst_getnode(t_list *lst, void *content)
{
	t_list	*node;

	if (lst == NULL || content == NULL)
		return (NULL);
	node = lst;
	while (node != NULL)
	{
		if (node->content == content)
			return (node);
		node = node->next;
	}
	return (NULL);
}
