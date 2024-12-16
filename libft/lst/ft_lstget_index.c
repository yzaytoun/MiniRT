/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:05:51 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 16:23:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstget_index(t_list *lst, int idx)
{
	t_list	*node;
	int		i;

	if (idx < 0)
		return (NULL);
	node = lst;
	i = 0;
	while (node)
	{
		if (idx == i)
			return (node->content);
		node = node->next;
		i++;
	}
	return (NULL);
}
