/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ufloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:25 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/17 12:18:26 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Reading integer
// 3 Point
// 4 Reading decimal
// 5 Spaces After
int	get_ufloat_comma(int i, int j)
{
	const int	states[][6] = {
	{0, 1, 2, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{0, 1, 2, 3, 0, 1},
	{1, 1, 4, 1, 1, 1},
	{5, 1, 4, 1, 0, 1},
	{5, 1, 1, 1, 0, 1},
	};

	return (states[i][j]);
}

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Reading integer
// 3 Point
// 4 Reading decimal
int	get_ufloat(int i, int j)
{
	const int	states[][6] = {
	{0, 1, 2, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{0, 1, 2, 3, 1, 1},
	{1, 1, 4, 1, 1, 1},
	{0, 1, 4, 1, 1, 1},
	};

	return (states[i][j]);
}
