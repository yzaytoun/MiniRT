/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:20:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/31 16:23:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countalpha(const char *string)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (string != NULL)
	{
		while (string[i] != '\0')
		{
			if (ft_isalpha(string[i]) != 0)
				count++;
			i++;
		}
	}
	return (count);
}
