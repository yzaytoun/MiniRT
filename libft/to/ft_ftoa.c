/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/16 19:32:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int	normalize(double *d)
{
	int		exponent;
	double	val;

	exponent = 0;
	val = *d;
	while (val >= 1.0)
	{
		val /= 10.0;
		++exponent;
	}
	while (val < 0.1)
	{
		val *= 10.0;
		--exponent;
	}
	*d = val;
	return (exponent);
}

static void	fill_exponent(double *d, char **buff, int *exponent, int pre)
{
	int	digit;

	digit = 0;
	(*exponent) = normalize(d);
	if (!(*exponent) || (*exponent) < 0)
		*(*buff)++ = '0';
	while ((*exponent) > 0)
	{
		digit = ((*d) * 10);
		*(*buff)++ = digit + '0';
		(*d) = (*d) * 10 - digit;
		--(*exponent);
	}
	if (pre)
		*(*buff)++ = '.';
}

static void	fill_string(double d, char **buff, int pre)
{
	int	places;
	int	digit;
	int	exponent;

	exponent = 0;
	places = 0;
	fill_exponent(&d, buff, &exponent, pre);
	while (exponent < 0 && places < pre)
	{
		*(*buff)++ = '0';
		++exponent;
		++places;
	}
	while (places < pre)
	{
		digit = d * 10.0;
		*(*buff)++ = digit + '0';
		d = d * 10.0 - digit;
		++places;
	}
	*(*buff) = '\0';
}

int	count_intdigits(double d)
{
	double	val;
	int		digitnum;

	digitnum = 0;
	val = d;
	if (val < 0)
	{
		val *= -1;
		++digitnum;
	}
	while (val >= 1.0)
	{
		val /= 10.0;
		++digitnum;
	}
	return (digitnum);
}

/*
	@brief converts double/float to string
	@param pre the number precision limit
*/
char	*ft_ftoa(double d, int pre)
{
	char	*str;
	char	*buff;
	int		int_count;

	if (d == INFINITY || d == NAN)
		return (ft_strdup("inf"));
	else if (d == -INFINITY)
		return (ft_strdup("-inf"));
	int_count = count_intdigits(d);
	if (!int_count && pre)
		int_count++;
	if (d == 0.0 || (!int_count && !pre))
		return (strdup("0.0"));
	str = malloc(sizeof(char) * (int_count + pre + 2));
	if (str)
	{
		buff = str;
		if (d < 0.0)
		{
			d *= -1;
			*(buff)++ = '-';
		}
		fill_string(d, &buff, pre);
	}
	return (str);
}
