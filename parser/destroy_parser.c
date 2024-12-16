/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:50:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/25 17:31:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	del_elements(void *content)
{
	t_input	*input;

	if (content)
	{
		input = (t_input *)content;
		if (input->inputs)
			ft_sarrfree(&input->inputs);
		free(input);
	}
}

void	destroy_parser(t_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_lstclear(&parser->elements, del_elements);
}
