/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:37:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/04/03 19:17:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_state_dict	t_sdict;

struct s_state_dict
{
	int		key;
	void	*value;
};

/* DICT */
t_sdict		*create_newdict(int key, void *value);
void		free_dict(void *content);
void		*get_sdict_value(const t_sdict *dict, int state);
void		*get_sdict_last(const t_sdict *dict);

#endif