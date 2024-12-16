/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:47:23 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/13 17:52:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mlximg	*create_img(t_mlx *mlx)
{
	t_mlximg	*img;

	img = malloc(sizeof(t_mlximg));
	img->width = WIN_W;
	img->height = WIN_H;
	img->ptr = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	scene_img_iter(t_scene *scene,
	void (*f)(t_scene *scene, int x, int y))
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			f(scene, x, y);
	}
}

void	img_iter_context(t_mlximg *img, void *data,
	void (*f)(t_mlximg *img, void *data, int x, int y))
{
	int		x;
	int		y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			f(img, data, x, y);
	}
}

t_mlximg	image_load(void *mlx, char *file)
{
	t_mlximg	img;

	img.ptr = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
	if (img.ptr)
		img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	return (img);
}
