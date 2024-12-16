/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:45:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/26 16:13:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	int		result;

	result = -1;
	if (!s1 || !s2)
		return (-1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 > len_s2)
		result = ft_strncmp(s1, s2, len_s1);
	else
		result = ft_strncmp(s1, s2, len_s2);
	return (result);
}
