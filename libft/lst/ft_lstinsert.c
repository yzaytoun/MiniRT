/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:03:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/04 20:08:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **list, void *content, t_position position)
{
	t_list	*newnode;

	newnode = NULL;
	if (content)
	{
		newnode = ft_lstnew(content);
		if (position == FRONT)
			ft_lstadd_front(list, newnode);
		else if (position == BACK)
			ft_lstadd_back(list, newnode);
	}
}
