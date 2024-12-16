/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:48:08 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/30 11:00:30 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

void	get_inputstr(t_automata *a, t_parser *pars)
{
	t_input		*in;
	char		*trim;
	char		*sub;

	if (!pars->elements)
		return ;
	in = ft_lstlast(pars->elements)->content;
	if (a->i)
	{
		sub = ft_substr(a->str, a->j, a->i - a->j + 1);
		trim = ft_strtrim(sub, " ,");
		free (sub);
		if (trim && trim[0])
			in->inputs = ft_sarradd(in->inputs, trim);
		free (trim);
		a->j = a->i + 1;
	}
}

void	newparse(t_automata *a, void *data)
{
	t_parser	*pars;

	pars = data;
	if (get_element(pars->reading, pars->step) >= 6)
		printerror("Error: More data than expected\n");
	get_inputstr(a, pars);
	a->get_state = pars->parsers[get_element(pars->reading, pars->step)];
	pars->step++;
}

void	errorparse(t_automata *a, void *data)
{
	t_parser	*pars;

	pars = data;
	printf("Error on element: %s at: %d\n", pars->names(pars->reading), a->i);
	exit(EXIT_FAILURE);
}

/**
 *  This function holds the kind of inputs spected from element type
 * 	it return the index of the state changer function of the automata.
**/
//  get_uint = 0, get_ufloat = 1, get_float = 2, get_uint_comma = 3,
//	get_ufloat_comma = 4, get_float_comma = 5, Error = 6
// 0 Ambient
// 1 Camera
// 2 Ligth
// 3 Plane
// 4 Sphere
// 5 Cylinder
// 6 Cone
int	get_element(int i, int j)
{
	const int	states[][12] = {
	{1, 3, 3, 0, 6, 6, 6, 6, 6, 6, 6, 6},
	{5, 5, 2, 5, 5, 2, 0, 6, 6, 6, 6, 6},
	{5, 5, 2, 1, 3, 3, 0, 6, 6, 6, 6, 6},
	{5, 5, 2, 5, 5, 2, 3, 3, 0, 6, 6, 6},
	{5, 5, 2, 1, 3, 3, 0, 6, 6, 6, 6, 6},
	{5, 5, 2, 5, 5, 2, 1, 1, 3, 3, 0, 6},
	{5, 5, 2, 5, 5, 2, 1, 1, 3, 3, 0, 6},
	};

	return (states[i][j]);
}
