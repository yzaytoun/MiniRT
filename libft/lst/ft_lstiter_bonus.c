/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:31:25 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 16:24:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *content))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

void	ft_lstiter_context(t_list *lst,
	void (*f)(void *content, void *context), void *context)
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content, context);
		temp = temp->next;
	}
}

t_list	*ft_lstiter_find(t_list *lst,
	int (*f)(void *content, void *context), void *context)
{
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	while (temp)
	{
		if (f(temp->content, context))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
