/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:05:51 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/12 15:27:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_index(t_list **node, void (*del)(void*), int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (*node)
	{
		if (index == i + 1 && (*node)->next)
		{
			tmp = (*node)->next;
			(*node)->next = (*node)->next->next;
			ft_lstdelone(tmp, del);
			break ;
		}
		(*node) = (*node)->next;
		i++;
	}
}

void	ft_lstdel_index(t_list **lst, void (*del)(void*), int index)
{
	t_list	*node;

	if (!lst || !del || !*lst || index < 0)
		return ;
	node = *lst;
	if (!index)
	{
		*lst = (*lst)->next;
		ft_lstdelone(node, del);
	}
	else
		del_index(&node, del, index);
}
