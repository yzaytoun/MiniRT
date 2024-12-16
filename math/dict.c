/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:40:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/04/03 19:18:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_sdict	*create_newdict(int key, void *value)
{
	t_sdict	*newdict;

	newdict = NULL;
	newdict = malloc(sizeof(t_sdict));
	if (newdict == NULL)
		return (NULL);
	newdict->key = key;
	newdict->value = value;
	return (newdict);
}

void	free_dict(void *content)
{
	t_sdict	*dict;

	dict = NULL;
	if (content == NULL)
		return ;
	dict = (t_sdict *)content;
	if (dict != NULL)
	{
		free(dict->value);
		free(dict);
	}
}

void	*get_sdict_value(const t_sdict *dict, int state)
{
	int		i;

	if (dict == NULL)
		return (NULL);
	i = 0;
	while (dict[i].value != NULL)
	{
		if (dict[i].key == state)
			return (dict[i].value);
		++i;
	}
	return (NULL);
}

void	*get_sdict_last(const t_sdict *dict)
{
	int		i;

	if (dict == NULL)
		return (NULL);
	i = 0;
	while (dict[i + 1].value != NULL)
		i++;
	return (dict[i].value);
}
