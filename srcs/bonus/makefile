NAME	= Cub3D

CC		= gcc

Make	= make

OS	= $(shell uname)

ifeq ($(DB),1)
    CFLAGS	= -D BONUS=1 -O3 -g3 -Wall -Wextra -Werror
	LIBS	= -L ../../libft/ -lft ${MLX_LNK} -lm
else
	CFLAGS	= -D BONUS=1 -O3 -Wall -Wextra -Werror
	LIBS	= -L ../../libft/ -lft ${MLX_LNK} -lm
endif

INC		= -I ../../includes/ -I ../../libft/includes/ -I $(MLX_DIR) -I ../get_next_line/

OBJS	= ${SRCS:.c=.o}

SRCS	=	../cub3d.c \
			../events/keyboard.c \
			../events/move_player.c \
			../events/rotate_camera.c \
			../parser/color_parser.c \
			../parser/exit_parser.c \
			../parser/leaks_check.c \
			../parser/map_parser.c \
			../parser/map_parser_utils.c \
			../parser/parser.c \
			../parser/parser_success.c \
			../parser/player_parser.c \
			../parser/sprite_parser.c \
			../parser/texture_parser.c \
			../raycaster/raycaster.c \
			../raycaster/raycaster_dda.c \
			../raycaster/raycaster_utils.c \
			../raycaster/sprites.c \
			../raycaster/walls.c \
			../sprites/sprites_utils.c \
			../utils/geometry.c \
			../utils/maths.c \
			../utils/memory.c \
			../utils/mlx_custom.c \
			../utils/quit.c \
			../utils/screenshot.c \
			../utils/strings.c \
			../get_next_line/get_next_line.c \
			../get_next_line/get_next_line_utils.c \
			../doors/doors_utils_bonus.c \
			../doors/doors_bonus.c \
			../raycaster/doors_cast_bonus.c \
			../utils/print_nbr_bonus.c \
			../raycaster/shaders_bonus.c \
			../raycaster/skybox_bonus.c \
			../raycaster/floor_bonus.c \
			../collisions/collision_bonus.c \
			../collisions/collision_sprite_bonus.c \
			../collisions/collision_sprite_utils_bonus.c \
			../collisions/collision_utils_bonus.c \
			../editor/editor_bonus.c \
			../events/keyboard_bonus.c \
			../parser/parser_bonus.c \
			../raycaster/column_bonus.c \
			../raycaster/corner_wall_bonus.c \
			../raycaster/pushwall_bonus.c \
			../raycaster/rounded_angle_bonus.c \
			../raycaster/sprites_bonus.c \
			../raycaster/sprites_interact_bonus.c \
			../raycaster/walls_bonus.c \
			../sprites/sprites_update_bonus.c

ifeq ($(OS), Linux)
	MLX_DIR	= ../../minilibx-linux
	MLX_LNK	= -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd
	SRCS	+=	../events/mouse_bonus.c \
				../parser/resolution_parser.c
else
	MLX_DIR	= ../../minilibx-opengl
	MLX_LNK	= -L ${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
	SRCS	+=	../events/mouse_mac_bonus.c \
				../parser/resolution_mac_parser.c
endif

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

${NAME}: ${OBJS}
		@echo "\033[33m-= Making Libft... =-"
		@make -C ../../libft
		@echo "\033[34m-= Making mlx... =-"
		@make -C $(MLX_DIR)
		@echo "\033[35m-= Making Cub3D... =-"
		${CC} ${CFLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}
		mv $(NAME) ../../$(NAME)
		@echo "\033[32m   ______      __   _____ ____     __                           "
		@echo "\033[32m  / ____/_  __/ /_ |__  // __ \   / /_  ____  ____  __  _______ "
		@echo "\033[32m / /   / / / / __ \ /_ </ / / /  / __ \/ __ \/ __ \/ / / / ___/ "
		@echo "\033[32m/ /___/ /_/ / /_/ /__/ / /_/ /  / /_/ / /_/ / / / / /_/ (__  )  "
		@echo "\033[32m\____/\__,_/_.___/____/_____/  /_.___/\____/_/ /_/\__,_/____/   usage: ./Cub3D <map.cub> [--save]"

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	@make fclean -C ../../libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re