/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:06:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/03/04 20:20:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Replace dest with the new string
	Frees the pointer of dest
*/
void	ft_strreplace(char **str_to_replace, char *new_str)
{
	if (str_to_replace == NULL || (*str_to_replace) == NULL || new_str == NULL)
		return ;
	free((*str_to_replace));
	(*str_to_replace) = new_str;
}
