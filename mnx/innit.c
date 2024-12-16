/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:34:21 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 15:40:03 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

static t_control	***create_cmatrix(int nrows, int ncolumns)
{
	t_control	***matrix;
	int			count_y;

	matrix = malloc(sizeof(t_control **) * nrows);
	if (matrix == NULL)
		return (NULL);
	count_y = -1;
	while (++count_y < nrows)
		matrix[count_y] = malloc(sizeof(t_control *) * ncolumns);
	return (matrix);
}

void	mnx_add_menu(t_mnx *mnx, t_menu *menu)
{
	ft_lstadd_back(&mnx->mnx_lst, ft_lstnew(menu));
	menu->matrix = mnx->matrix;
	menu->img = mnx->img;
}

t_menu	*mnx_get_menu(t_mnx *mnx, int idx)
{
	return ((t_menu *)ft_lstget_index(mnx->mnx_lst, idx));
}

void	mnx_draw(t_mnx *mnx)
{
	ft_lstiter(mnx->mnx_lst, mnx_menu_draw);
}

// Creates a mnx manager.
t_mnx	mnx_innit(void *mlx, void *win, int win_width, int win_height)
{
	t_mnx	mnx;

	mnx.mlx = mlx;
	mnx.win = win;
	mnx.img = mnx_img_new(mlx, win_width, win_height);
	mnx.matrix = create_cmatrix(win_width, win_height);
	mnx.win_width = win_width;
	mnx.win_height = win_height;
	matrix_clear(mnx.matrix, win_width, win_height);
	mnx.mnx_lst = NULL;
	mnx.add = mnx_add_menu;
	mnx.get = mnx_get_menu;
	mnx.draw = mnx_draw;
	return (mnx);
}
