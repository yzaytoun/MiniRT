/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:04:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/04/06 20:16:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "automata.h"

typedef struct s_input		t_input;
typedef enum e_elmenttype	t_elementtype;

enum e_elmenttype
{
	AMBIENT = 1,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	VIEW,
	DEFAULT,
	TYPE_MAX
};

struct s_input
{
	t_elementtype	type;
	char			**inputs;
};

typedef struct s_parser
{
	t_list		*elements;
	int			reading;
	int			step;
	int			(*parsers[20])(int i, int j);
	const char	*(*names)(int index);
}	t_parser;

typedef enum e_parsing
{
	P_EMPTY,
	P_ERROR,
}	t_parsing;

/* Innit */
void		errors_init(t_automata *a);
void		init_parser(t_parser *pars);
void		alphabet_init(t_automata *a);
void		automata_init(t_automata *a, void *data);
void		start_parser(t_parser *pars, t_automata *a, int reading);
t_parser	parse_input_file(char *filename);
void		destroy_parser(t_parser *parser);
void		destroy_automata(t_automata *a);

/* States changers */
int			get_uint(int i, int j);
int			get_uint_comma(int i, int j);
int			get_float(int i, int j);
int			get_float_comma(int i, int j);
int			get_ufloat(int i, int j);
int			get_ufloat_comma(int i, int j);
int			get_element(int i, int j);

/* Utils */
void		printerror(const char *str);
void		read_file(t_parser *pars, char *dir);
void		get_inputstr(t_automata *a, t_parser *pars);

/* Single Actions */
void		sactions_init(t_automata *a);

/* Transition Actions */
void		tactions_init(t_automata *a);
void		newparse(t_automata *a, void *data);
void		errorparse(t_automata *a, void *data);

/*Debug*/
void		printelements(t_parser parser);

#endif