/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:25:36 by jvasquez          #+#    #+#             */
/*   Updated: 2022/11/22 18:27:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_bit(int n, int bit)
{
	return (n >> bit & 1);
}
