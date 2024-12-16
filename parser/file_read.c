/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:56:21 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/30 11:00:04 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

void	check_line(t_parser *pars, t_automata *a, char *line)
{
	a->str = line + 2;
	if (!ft_strncmp(line, "A ", 2))
		start_parser(pars, a, 0);
	else if (!ft_strncmp(line, "C ", 2))
		start_parser(pars, a, 1);
	else if (!ft_strncmp(line, "L ", 2))
		start_parser(pars, a, 2);
	else if (!ft_strncmp(line, "pl ", 3))
		start_parser(pars, a, 3);
	else if (!ft_strncmp(line, "sp ", 3))
		start_parser(pars, a, 4);
	else if (!ft_strncmp(line, "cy ", 3))
		start_parser(pars, a, 5);
	else if (!ft_strncmp(line, "cn ", 3))
		start_parser(pars, a, 6);
	else if (line[0] != ' ' && line[0] != '#' && line[0] != '\0')
		printerror("Error");
	if (evaluate(a) == 1)
		printerror("Error");
	get_inputstr(a, pars);
}

void	ft_to_space(unsigned int i, char *c)
{
	(void)i;
	if (ft_isspace(*c))
		*c = ' ';
}

void	read_file(t_parser *pars, char *dir)
{
	int			file;
	char		*line;
	char		*trim;
	t_automata	a;

	ft_bzero(&a, sizeof(t_automata));
	automata_init(&a, pars);
	file = open(dir, O_RDONLY);
	if (file == -1)
		printerror("File not found");
	line = get_next_line(file);
	while (line)
	{
		ft_striteri(line, ft_to_space);
		trim = ft_strtrim(line, " ");
		free (line);
		if (trim[0] != '#' && trim[0] != '\000')
			check_line(pars, &a, trim);
		free (trim);
		line = get_next_line(file);
	}
	destroy_automata(&a);
	close(file);
}
