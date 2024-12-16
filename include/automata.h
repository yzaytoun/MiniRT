/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:05 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/25 18:27:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H

# define STATE_NULL -1

typedef struct s_automata	t_automata;

struct s_automata
{
	void	*data;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		state;
	int		oldstate;
	int		errorlen;
	int		i;
	int		j;
	void	(*fsa[20])(t_automata *a, void *data);
	void	(**(*fta))(t_automata *a, void *data);
	int		(*get_state)(int state, int abc_idx);
	void	*(*get_data)(t_automata *a);
	int		(*is_validestate)(int);
};

int			evaluate(t_automata *a);
void		evaluate_file(t_automata *a,
				char *dir, void (*f)(t_automata *, int));

#endif
