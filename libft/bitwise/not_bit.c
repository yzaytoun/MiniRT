/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:00:21 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/24 20:00:22 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_bit(int *n, int bit)
{
	if (bit >= 32 || bit < 0)
		return (0);
	if (*n >> bit & 1)
		*n = *n - (1 << bit);
	else
		*n = *n + (1 << bit);
	return (1);
}
