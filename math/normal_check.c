/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:40:53 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 18:41:07 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	normal_check(t_point point)
{
	if (point.x > 1 || point.x < -1
		|| point.y > 1 || point.y < -1
		|| point.z > 1 || point.z < -1)
		return (0);
	return (1);
}
