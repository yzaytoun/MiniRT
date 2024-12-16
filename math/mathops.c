/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:17:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/07/19 16:25:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

/*
	@returns max number in the array, else 0
*/
double	max(double array[], int size)
{
	int		x;
	double	maxval;

	if (!array || size < 0)
		return (0);
	x = 0;
	maxval = array[0];
	while (x < size)
	{
		if (array[x] > maxval)
			maxval = array[x];
		x++;
	}
	return (maxval);
}

/*
	@returns min number in the array, else 0
*/
double	min(double array[], int size)
{
	int		x;
	double	minval;

	if (!array || size < 0)
		return (0);
	x = 0;
	minval = array[0];
	while (x < size)
	{
		if (array[x] < minval)
			minval = array[x];
		x++;
	}
	return (minval);
}
