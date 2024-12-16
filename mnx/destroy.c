/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:36:04 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/07 14:58:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

void	del_menu(void *data)
{
	t_menu	*menu;

	if (data == NULL)
		return ;
	menu = (t_menu *)data;
	ft_lstclear(&menu->controls.list, mnx_control_del);
	if (menu->background.ptr)
		mlx_destroy_image(menu->mlx, menu->background.ptr);
	free (menu);
}

void	del_matrix(t_control ***matrix, int win_width)
{
	t_point2D	p;

	p.x = -1;
	while (++p.x < win_width)
		free(matrix[p.x]);
	free(matrix);
}

void	mnx_destroy(t_mnx *mnx)
{
	ft_lstclear(&mnx->mnx_lst, del_menu);
	del_matrix(mnx->matrix, mnx->win_width);
	if (mnx->img.ptr)
		mlx_destroy_image(mnx->mlx, mnx->img.ptr);
}
