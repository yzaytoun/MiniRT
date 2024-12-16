/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mask_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:52:19 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 16:20:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if every bit in "with" is in the same state in "mask".
int	check_mask_and(int mask, int with)
{
	const int	result = mask & with;

	if (result == with)
		return (1);
	return (0);
}
