/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:08:02 by jvasquez          #+#    #+#             */
/*   Updated: 2024/10/22 18:37:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnx_menu.h"

void	update_bar_img(t_control *c)
{
	t_pbar		*bar;
	t_point2D	pix;

	bar = c->bar;
	if (!bar->draw_eq)
		return ;
	pix.x = -1;
	while (++pix.x < c->dim.x)
	{
		pix.y = -1;
		while (++pix.y < c->dim.y)
			my_mlx_pixel_put(&c->img, pix.x, pix.y,
				bar->draw_eq(c, pix.x, pix.y, bar->progress));
	}
}

// Write to end img and clean pixels using background.
void	mnx_img_to_img(t_mlximg *end, t_mlximg *wr, t_point2D pos)
{
	char		*dst;
	char		*org;
	t_point2D	pixel;

	pixel.x = 0;
	while (pixel.x < wr->width && (pixel.x + pos.x) < end->width)
	{
		pixel.y = 0;
		while (pixel.y < wr->height && (pixel.y + pos.y) < end->height)
		{
			dst = end->addr + ((pixel.y + pos.y) * end->line_length
					+ (pixel.x + pos.x) * (end->bits_per_pixel / 8));
			org = wr->addr + (pixel.y * wr->line_length
					+ pixel.x * (wr->bits_per_pixel / 8));
			if (*(unsigned int *)org != 0xFF000000)
				*(unsigned int *)dst = *(unsigned int *)org;
			pixel.y++;
		}
		pixel.x++;
	}
}

void	draw_control(void *data, void *context)
{
	t_control	*c;
	t_menu		*menu;
	t_point2D	p;

	if (!data || !context)
		return ;
	c = (t_control *)data;
	menu = (t_menu *)context;
	if (c->bar)
		update_bar_img(c);
	if (c->img.ptr && menu->img.ptr)
		mnx_img_to_img(&menu->img, &c->img,
			(t_point2D){menu->pos.x + c->pos.x, menu->pos.y + c->pos.y});
	if (c->label)
		mlx_string_put(menu->mlx, menu->win, menu->pos.x + c->label->pos.x,
			menu->pos.y + c->label->pos.y, c->label->color, c->label->text);
	p.x = menu->pos.x + c->pos.x;
	while (++p.x < menu->pos.x + c->pos.x + c->dim.x)
	{
		p.y = menu->pos.y + c->pos.y;
		while (++p.y < menu->pos.y + c->pos.y + c->dim.y)
			if (p.x < WIN_W && p.y < WIN_H)
				menu->matrix[p.x][p.y] = c;
	}
}

void	draw_label(void *data, void *context)
{
	t_control	*c;
	t_menu		*menu;

	c = (t_control *)data;
	menu = (t_menu *)context;
	if (c->label)
		mlx_string_put(menu->mlx, menu->win, menu->pos.x + c->label->pos.x,
			menu->pos.y + c->label->pos.y, c->label->color, c->label->text);
}

// Dibuja el menú
void	mnx_menu_draw(void *data)
{
	t_menu	*menu;

	if (!data)
		return ;
	menu = (t_menu *)data;
	if (!menu || !menu->visible)
		return ;
	if (menu->img.ptr && menu->background.ptr)
		mnx_img_to_img(&menu->img, &menu->background,
			(t_point2D){menu->pos.x, menu->pos.y});
	ft_lstiter_context(menu->controls.list, draw_control, menu);
	mlx_put_image_to_window(menu->mlx, menu->win, menu->img.ptr, 0, 0);
	ft_lstiter_context(menu->controls.list, draw_label, menu);
}
