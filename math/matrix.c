/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:44:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/04/06 16:37:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	destroy_matrix(t_generic ***(*matrix), int nrows)
{
	int	count_y;

	if (matrix == NULL || (*matrix) == NULL)
		return ;
	count_y = 0;
	while (count_y < nrows)
	{
		if ((*matrix)[count_y] != NULL)
			free((*matrix)[count_y]);
		count_y++;
	}
	free((*matrix));
	(*matrix) = NULL;
}

static t_generic	***create_matrix(int nrows, int ncolumns)
{
	t_generic	***matrix;
	int			count_y;

	matrix = malloc(sizeof(t_generic **) * nrows);
	if (matrix == NULL)
		return (NULL);
	count_y = 0;
	while (count_y < nrows)
	{
		matrix[count_y] = malloc(sizeof(t_generic *) * ncolumns);
		if (matrix[count_y] == NULL)
		{
			destroy_matrix(&matrix, count_y);
			break ;
		}
		count_y++;
	}
	return (matrix);
}

t_geomatrix	*new_geomatrix(int nrows, int ncolumns)
{
	t_geomatrix	*geomatrix;

	geomatrix = malloc(sizeof(t_geomatrix));
	if (geomatrix == NULL)
		return (NULL);
	geomatrix->matrix = create_matrix(nrows, ncolumns);
	geomatrix->nrows = nrows;
	geomatrix->ncolumns = ncolumns;
	return (geomatrix);
}

void	destroy_geomatrix(t_geomatrix **geomatrix)
{
	if ((geomatrix == NULL) | ((*geomatrix) == NULL))
		return ;
	destroy_matrix(&(*geomatrix)->matrix, (*geomatrix)->nrows);
	free((*geomatrix));
}
