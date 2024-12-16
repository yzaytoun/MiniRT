# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 21:26:35 by jvasquez          #+#    #+#              #
#    Updated: 2024/12/16 09:47:54 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

vpath %.h libft: ../minilibx_opengl_20191021 : minilibx-linux : include : mnx : octree
vpath %.c parser : src : automata : math : ui : mnx : octree : src/elements : src/materials
vpath %.o .obj : mnx
vpath %.a minilibx-linux

BANNER=\
	$(info __   __  ___   __    _  ___     ______    _______ )\
$(info |  |_|  ||   | |  |  | ||   |   |    _ |  |       |)\
$(info |       ||   | |   |_| ||   |   |   | ||  |_     _|)\
$(info |       ||   | |       ||   |   |   |_||_   |   |  )\
$(info |       ||   | |  _    ||   |   |    __  |  |   |  )\
$(info | ||_|| ||   | | | |   ||   |   |   |  | |  |   |  )\
$(info |_|   |_||___| |_|  |__||___|   |___|  |_|  |___|  )\
$(info -------------------------------------------------  )

# ------------------------ MLX CONFIG ------------------------------

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	MLXDIR = minilibx-linux
	MLXFLAGS = -lmlx -lXext -lX11 -lm -lbsd
	MLXLIB = $(MLXDIR)/libmlx_Linux.a $(MLXDIR)/libmlx.a
	KEY_MACRO = -D LINUX
else
	MLXDIR = ../minilibx_opengl_20191021
	MLXFLAGS = -lm -lmlx -framework OpenGL -framework AppKit
	MLXLIB = $(MLXDIR)/libmlx.a
endif

# ---------------------- VARIABLES -------------------------------

MLXCONFIG = -L$(MLXDIR) $(MLXFLAGS) $(MLXLIB)
INCLUDES = -Ilibft -I$(MLXDIR) -Iinclude -Imnx -Ioctree
CFLAGS := -Wall -Wextra -Werror $(KEY_MACRO) $(INCLUDES) -g -Ofast -funsafe-math-optimizations
CC := clang
DIR_LIB = ./libft/
LIBFT = ./libft/libft.a
DIR_MNX = ./mnx/
MNX = ./mnx/menu.a
RM := rm -fr

SANITIZER = -fsanitize=address -g3

SRC =	main.c				\
		create_element.c	\
		create_geometry.c	\
		hit_cylinder.c		\
		hit_geometry.c		\
		hit_geom.c 			\
		hit_element.c 		\
		hit_light.c			\
		hooks.c				\
		image.c				\
		debug.c				\
		ray.c				\
		create_scene.c		\
		scene_utils.c		\
		valid_fileformat.c	\
		color.c				\
		color_ops.c			\
		lights.c			\
		generic.c			\
		render.c			\
		viewport.c			\
		mouse_hooks.c		\
		checkers.c			\
		matrix.c			\
		modify_geometry.c	\
		hit_cone.c			\
		random.c			\
		dimensions.c		\
		backup.c			\
		update.c			\
		exit_scene.c		\
		material.c			\
		checkerboard.c		\
		uv_coord_at.c		\
		bbox.c				\
		rt_logger.c			\
		delete_geometry.c

PAR =	get_float.c			\
		get_uint.c			\
		get_ufloat.c		\
		file_read.c			\
		actions.c			\
		parser.c			\
		ainit.c				\
		destroy_parser.c

AUT =	automata.c

MATH =	operations.c 		\
		operations2.c		\
		rotate.c 			\
		vectors.c 			\
		normal_at.c			\
		normal_check.c		\
		vector_operations.c	\
		color_conversion.c	\
		angle.c				\
		new_element.c		\
		dict.c				\
		point.c				\
		mathops.c			\
		angles.c

UI =	cam_control.c		\
		bar_eq.c			\
		menu_material_sets.c\
		menu_checker_sets.c	\
		menu_options_sets.c	\
		create_menu.c		\
		menu_init.c			\
		menu_material.c		\
		menu_options.c		\
		menu_upper.c		\
		menu_color.c		\
		menu_checker.c		\
		button_close.c

OCTREE = 	octree.c				\
			octree_utils.c			\
			octree_init.c			\
			octreesubdivide_node.c	\
			octree_log.c			\
			octreeiter.c			\
			octreenav.c				\
			octree_insert.c			\
			octreeinsert_objects.c	\
			get_next_neighbour.c	\
			reallocate_element.c

SRC_ALL = $(SRC) $(PAR) $(AUT) $(MATH) $(UI) $(OCTREE)

OBJS = ${SRC_ALL:%.c=$(OBJDIR)/%.o}
OBJDIR = .obj

$(OBJDIR)/%.o : %.c
	@echo Compiling $<
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

# gcc libft/libft.a -lmlx -framework OpenGL -framework AppKit && ./a.out

$(NAME):	$(BANNER) $(LIBFT) $(MNX) $(MLXLIB) $(OBJS)
			@echo "\nMaking MiniRT\n"
			$(CC) $(OBJS) $(LIBFT) $(MNX) $(MLXCONFIG) -o $@ $(SANITIZER)
			@echo "-----MiniRT ready------\n"

all: $(NAME)

$(LIBFT):
		@echo "\nMaking libft\n"
		$(MAKE) -C $(DIR_LIB);

$(MNX):
		@echo "\nMaking mlx menu\n"
		$(MAKE) -C $(DIR_MNX);

$(MLXLIB):
		echo "\n--------------------------\n"
		echo "Making MLX\n"
		$(MAKE) -C $(MLXDIR)
		echo "--------------------------\n\n"

clean:
		@echo "\nCleaning Object files"
		$(RM) $(OBJS) $(OBJDIR)
		@echo "Cleaning libft"
		make fclean -C $(DIR_LIB)
		@echo "Cleaning mlx menu"
		make fclean -C $(DIR_MNX)
		@echo "Cleaning MLX"
		make clean -C $(MLXDIR)

fclean: clean
		$(RM) $(NAME) $(RT_DEV)
		@echo "\nFinished Cleaning...\n"
		@echo "--------------------"

re: fclean all 

pylone: 	$(NAME)
			@echo "\nFin"
			./miniRT

memcheck: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$< scene.rt

norminette:
	norminette automata include libft math mnx octree parser src ui

.SILENT:
.PHONY: re fclean all pylone