/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:07:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/30 18:22:25 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	int		pos;
	int		in;
	double	de;
	int		i;
	int		sign;

	de = 0;
	pos = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1 + pos++;
	in = ft_atoi_pos(str, &pos);
	if (str[pos++] == '.')
	{
		i = 0;
		de = 1;
		while (ft_isdigit(str[pos + i++]))
			de *= 10;
		de = ft_atoi_pos(str, &pos) / de;
	}
	return (((double)in + de) * sign);
}
