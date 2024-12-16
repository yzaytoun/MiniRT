/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:53:38 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/13 18:59:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "automata.h"

int	idx(char *alphabet[], char c)
{
	int	i;

	i = -1;
	while (alphabet[++i])
		if (ft_chrpos(alphabet[i], c, 0) != -1)
			return (i);
	return (i);
}

int	evaluate(t_automata *a)
{
	a->oldstate = 0;
	a->i = -1;
	while (++a->i < (int)ft_strlen(a->str))
	{
		a->state = a->get_state(a->state, idx(a->alphabet, a->str[a->i]));
		if (a->fsa[a->state])
			a->fsa[a->state](a, a->data);
		if (a->fta[a->oldstate][a->state])
			a->fta[a->oldstate][a->state](a, a->data);
		a->oldstate = a->state;
	}
	return (a->state);
}

void	evaluate_file(t_automata *a, char *dir,
		void (*f)(t_automata *, int))
{
	int		file;
	char	*line;

	file = open(dir, O_RDONLY);
	line = get_next_line(file);
	while (line)
	{
		a->str = line;
		a->state = 0;
		f(a, evaluate(a));
		free (line);
		line = get_next_line(file);
	}
	close(file);
}

void	destroy_automata(t_automata *a)
{
	int	i;

	ft_sarrfree(&a->alphabet);
	ft_sarrfree(&a->errors);
	i = -1;
	while (++i < 20)
		free(a->fta[i]);
	free(a->fta);
}
