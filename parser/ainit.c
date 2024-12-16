/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/26 11:52:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

void	automata_init(t_automata *a, void *data)
{
	a->data = data;
	alphabet_init(a);
	errors_init(a);
	sactions_init(a);
	tactions_init(a);
}

/**
 * 	Alphabet definitions
**/
void	alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "-");
	a->alphabet = ft_sarradd(a->alphabet, "0123456789");
	a->alphabet = ft_sarradd(a->alphabet, ".");
	a->alphabet = ft_sarradd(a->alphabet, ",");
}

/**
 * 	Error strings to print when automata finish on a
 * 		non finish state.
**/
void	errors_init(t_automata *a)
{
	a->errors = NULL;
	a->errors = ft_sarradd(NULL, " ");
	a->errors = ft_sarradd(a->errors, "Invalid character");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when getting a certain state. 
**/
void	sactions_init(t_automata *a)
{
	a->fsa[P_ERROR] = errorparse;
}

/**
 *	Transition actions, they trigger when going
 * 		from a certain state to another.
**/
void	tactions_init(t_automata *a)
{
	void	(**(*func))(t_automata *, void *);
	int		i;
	int		j;

	i = -1;
	a->fta = malloc(sizeof(func) * 20);
	if (!a->fta)
		return ;
	while (++i < 20)
	{
		a->fta[i] = malloc(sizeof(*func) * 20);
		if (a->fta[i])
		{
			if (i > 0)
				a->fta[i][P_EMPTY] = newparse;
			else
				a->fta[i][P_EMPTY] = NULL;
			j = 0;
			while (++j < 20)
				a->fta[i][j] = NULL;
		}
	}
}
//void	tactions_init(t_automata *a)
//{
//	int	i;
//
//	i = 0;
//	while (++i < 20)
//		a->fta[i][P_EMPTY] = newparse;
//}