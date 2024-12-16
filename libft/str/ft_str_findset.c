/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_findset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:18:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/13 20:27:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Returns 1 if one of the characters in set is found in str
	Else returns 0
*/
int	ft_str_findset(const char *str, const char *set)
{
	int	i;

	i = 0;
	if (str != NULL && set != NULL)
	{
		while (str[i] != '\0')
		{
			if (ft_strchr(set, str[i]) != NULL)
				return (1);
			++i;
		}
	}
	return (0);
}
