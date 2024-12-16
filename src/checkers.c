/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:38:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/23 20:20:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"

t_bool	is_strempty(char *string)
{
	if (string != NULL || string[0] != '\0')
		return (FALSE);
	return (TRUE);
}

t_bool	isvalid_color(t_color color)
{
	if (color.r > 255 || color.g > 255 || color.b > 255)
		return (FALSE);
	return (TRUE);
}
