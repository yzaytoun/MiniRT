/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:57:24 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/07 14:53:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

void	mnx_control_del(void *data)
{
	t_control	*control;

	if (data)
	{
		control = (t_control *)data;
		if (control->bar)
			free(control->bar);
		if (control->label)
		{
			if (control->label->text)
				free(control->label->text);
			free(control->label);
		}
		if (control->img.ptr)
			mlx_destroy_image(control->menu->mlx, control->img.ptr);
		free(control);
	}
}

// Añade un botón al menú
t_control	*mnx_control_create(t_menu *menu, int dim_x, int dim_y)
{
	t_control	*control;

	control = malloc(sizeof(t_control));
	ft_bzero(control, sizeof(t_control));
	control->menu = menu;
	control->idx = menu->controls.count++;
	control->dim.x = dim_x;
	control->dim.y = dim_y;
	ft_lstadd_back(&menu->controls.list, ft_lstnew(control));
	return (control);
}

// Function list iter context
void	mnx_control_enumerate(void *data, void *context)
{
	t_control	*b;
	t_menu		*menu;

	b = (t_control *)data;
	menu = (t_menu *)context;
	b->idx = menu->controls.count++;
}

void	mnx_control_delete(t_menu *menu, int index)
{
	if (index > menu->controls.count || index < 0 || !menu->controls.count)
		return ;
	ft_lstdel_index(&menu->controls.list, mnx_control_del, index);
	menu->controls.count = 0;
	ft_lstiter_context(menu->controls.list, mnx_control_enumerate, menu);
}

t_control	*mnx_get_control(t_list *controls, int idx)
{
	return ((t_control *)ft_lstget_index(controls, idx));
}
