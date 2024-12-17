/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/12/16 10:32:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

int	main(int ac, char **av)
{
	t_scene		scene;
	t_parser	parser;

	if (ac == 2)
	{
		parser = parse_input_file(av[1]);
		scene = create_scene(parser.elements);
		destroy_parser(&parser);
		add_mlx(&scene, av[1]);
		create_menus(&scene);
		if (scene.geom_count > OBJ_LIMIT)
			octree_init(&scene);
		render(&scene);
		launch_window_hook(&scene);
	}
	else
	{
		printerror("Error: Only one argument !!");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
