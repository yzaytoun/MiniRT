/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:46:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/14 15:30:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Print double or float in fd
*/
void	ft_putdbl_fd(double d, int pre, int fd)
{
	char	*buff;

	buff = NULL;
	if (fd >= 0)
	{
		buff = ft_ftoa(d, pre);
		ft_putstr_fd(buff, fd);
		if (buff)
			free(buff);
	}
}
