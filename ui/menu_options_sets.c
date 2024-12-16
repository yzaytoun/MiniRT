/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_options_sets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:17 by jvasquez          #+#    #+#             */
/*   Updated: 2024/09/01 17:40:34 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"

void	bar_set_alight_red(t_control *control)
{
	bar_set_alight_color(control, TRUE, FALSE, FALSE);
}

void	bar_set_alight_green(t_control *control)
{
	bar_set_alight_color(control, FALSE, TRUE, FALSE);
}

void	bar_set_alight_blue(t_control *control)
{
	bar_set_alight_color(control, FALSE, FALSE, TRUE);
}
