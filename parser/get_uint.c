/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:16 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/17 12:18:17 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Number
// 3 Spaces After
int	get_uint_comma(int i, int j)
{
	const int	states[][6] = {
	{0, 1, 2, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{3, 1, 2, 1, 0, 1},
	{3, 1, 1, 1, 0, 1},
	};

	return (states[i][j]);
}

//   \s, -, D, ., ,, ^
// 0 Empty input
// 1 Invalid Character
// 2 Number
int	get_uint(int i, int j)
{
	const int	states[][6] = {
	{0, 1, 2, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{0, 1, 2, 1, 1, 1},
	};

	return (states[i][j]);
}
