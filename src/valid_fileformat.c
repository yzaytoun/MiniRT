/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fileformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/04 18:57:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	valid_fileformat(const char *filename)
{
	char	*file_suffix;

	if (filename == NULL)
		return (FALSE);
	file_suffix = ft_strrchr(filename, '.');
	if (file_suffix != NULL)
	{
		if (ft_strcmp(file_suffix, ".rt") == 0)
			return (TRUE);
	}
	return (FALSE);
}
