/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:20:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/25 16:03:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	delete_geometry(void *content, void *context)
{
	t_generic	*generic;

	if (content == NULL)
		return ;
	generic = (t_generic *)content;
	if (generic->dim != NULL)
		free(generic->dim);
	clear_material(&generic->material, context);
	free(generic);
	generic = NULL;
}
