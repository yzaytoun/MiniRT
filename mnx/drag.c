/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:10:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 15:46:35 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

// Button drag
int	mnx_button_drag(t_menu *menu, t_control *button, int x, int y)
{
	if (check_mask_and(menu->events, M_DRAGING) && button->dragable)
	{
		button->pos.x = button->pos.x + x - menu->mouse.x;
		button->pos.y = button->pos.y + y - menu->mouse.y;
		menu->mouse.x = x;
		menu->mouse.y = y;
		return (1);
	}
	else
		return (0);
}

// Pbar drag
int	mnx_pbar_drag(t_menu *menu, t_control *ctrl, int x, int y)
{
	t_pbar	*pb;

	(void)y;
	pb = ctrl->bar;
	if (!pb)
		return (0);
	if (check_mask_and(menu->events, M_DRAGING) && ctrl->dragable)
	{
		pb->progress = (int)(((float)(x - menu->pos.x - ctrl->pos.x) * 100.0)
				/ (float)ctrl->dim.x);
		if (pb->progress > 100)
			pb->progress = 100;
		if (pb->progress < 0)
			pb->progress = 0;
		return (1);
	}
	else
		return (0);
}

int	mnx_control_drag(t_menu *menu, t_control *ctrl, int x, int y)
{
	if (!ctrl || !menu)
		return (0);
	if (ctrl->bar)
		return (mnx_pbar_drag(menu, ctrl, x, y));
	else
		return (mnx_button_drag(menu, ctrl, x, y));
}
