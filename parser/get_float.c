/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:33 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/17 12:18:33 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Minus
// 3 Reading integer
// 4 Point
// 5 Reading decimal
// 6 Spaces after
int	get_float_comma(int i, int j)
{
	const int	states[][6] = {
	{0, 2, 3, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 3, 1, 1, 1},
	{6, 1, 3, 4, 0, 1},
	{1, 1, 5, 1, 1, 1},
	{6, 1, 5, 1, 0, 1},
	{6, 1, 1, 1, 0, 1},
	};

	return (states[i][j]);
}

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Minus
// 3 Reading integer
// 4 Point
// 5 Reading decimal
int	get_float(int i, int j)
{
	const int	states[][6] = {
	{0, 2, 3, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 3, 1, 1, 1},
	{0, 1, 3, 4, 1, 1},
	{1, 1, 5, 1, 1, 1},
	{0, 1, 1, 1, 1, 1},
	};

	return (states[i][j]);
}
