/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 08:51:59 by jvasquez          #+#    #+#             */
/*   Updated: 2024/08/31 19:15:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

const char	*get_element_name(int index)
{
	const char	*names[] = {
		"Ambient",
		"Camera",
		"Light",
		"Plane",
		"Sphere",
		"Cylinder",
		"Cone",
	};

	return (names[index]);
}

void	init_parser(t_parser *pars)
{
	pars->parsers[0] = get_uint;
	pars->parsers[1] = get_ufloat;
	pars->parsers[2] = get_float;
	pars->parsers[3] = get_uint_comma;
	pars->parsers[4] = get_ufloat_comma;
	pars->parsers[5] = get_float_comma;
	pars->names = get_element_name;
}

void	start_parser(t_parser *pars, t_automata *a, int reading)
{
	t_input	*input;

	pars->reading = reading;
	pars->step = 0;
	a->state = 0;
	input = malloc(sizeof(t_input));
	ft_bzero(input, sizeof(t_input));
	input->type = reading + 1;
	if (!pars->elements)
		pars->elements = ft_lstnew(input);
	else
		ft_lstadd_back(&pars->elements, ft_lstnew(input));
	newparse(a, pars);
	a->i = 0;
	a->j = 0;
}

t_parser	parse_input_file(char *filename)
{
	t_parser	pars;

	ft_bzero(&pars, sizeof(t_parser));
	init_parser(&pars);
	if (valid_fileformat(filename) == TRUE)
		read_file(&pars, filename);
	else
		printerror("Error: Invalid file format");
	return (pars);
}
