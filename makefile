NAME	= Cub3D

CC		= gcc

Make	= make

OS	= $(shell uname)

ifeq ($(DB),1)
    CFLAGS	= -O3 -g3 -Wall -Wextra -Werror
	LIBS	= -L libft/ -lft ${MLX_LNK} -lm
	MKBONUS	= DB=1 -C srcs/bonus
else
	CFLAGS	= -O3 -Wall -Wextra -Werror
	LIBS	= -L libft/ -lft ${MLX_LNK} -lm
	MKBONUS	= -C srcs/bonus
endif

INC		= -I includes/ -I libft/includes/ -I $(MLX_DIR) -I srcs/get_next_line/

OBJS	= ${SRCS:.c=.o}

SRCS	=	srcs/cub3d.c \
			srcs/events/keyboard.c \
			srcs/events/move_player.c \
			srcs/events/rotate_camera.c \
			srcs/parser/color_parser.c \
			srcs/parser/exit_parser.c \
			srcs/parser/leaks_check.c \
			srcs/parser/map_parser.c \
			srcs/parser/map_parser_utils.c \
			srcs/parser/parser.c \
			srcs/parser/parser_success.c \
			srcs/parser/player_parser.c \
			srcs/parser/sprite_parser.c \
			srcs/parser/texture_parser.c \
			srcs/raycaster/raycaster.c \
			srcs/raycaster/raycaster_dda.c \
			srcs/raycaster/raycaster_utils.c \
			srcs/raycaster/sprites.c \
			srcs/raycaster/walls.c \
			srcs/sprites/sprites_utils.c \
			srcs/utils/geometry.c \
			srcs/utils/maths.c \
			srcs/utils/memory.c \
			srcs/utils/mlx_custom.c \
			srcs/utils/quit.c \
			srcs/utils/screenshot.c \
			srcs/utils/strings.c \
			srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \
			srcs/doors/doors_utils_bonus.c \
			srcs/doors/doors_bonus.c \
			srcs/raycaster/doors_cast_bonus.c \
			srcs/utils/print_nbr_bonus.c \
			srcs/raycaster/shaders_bonus.c \
			srcs/raycaster/skybox_bonus.c \
			srcs/raycaster/floor_bonus.c \
			srcs/collisions/collision_bonus.c \
			srcs/collisions/collision_sprite_bonus.c \
			srcs/collisions/collision_sprite_utils_bonus.c \
			srcs/collisions/collision_utils_bonus.c \
			srcs/editor/editor_bonus.c \
			srcs/events/keyboard_bonus.c \
			srcs/parser/parser_bonus.c \
			srcs/raycaster/column_bonus.c \
			srcs/raycaster/corner_wall_bonus.c \
			srcs/raycaster/pushwall_bonus.c \
			srcs/raycaster/rounded_angle_bonus.c \
			srcs/raycaster/sprites_bonus.c \
			srcs/raycaster/sprites_interact_bonus.c \
			srcs/raycaster/walls_bonus.c \
			srcs/sprites/sprites_update_bonus.c

ifeq ($(OS), Linux)
	MLX_DIR	= minilibx-linux
	MLX_LNK	= -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd
	SRCS	+=	srcs/events/mouse_bonus.c \
				srcs/parser/resolution_parser.c
else
	MLX_DIR	= minilibx-opengl
	MLX_LNK	= -L ${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
	SRCS	+=	srcs/events/mouse_mac_bonus.c \
				srcs/parser/resolution_mac_parser.c
endif

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

${NAME}: ${OBJS} ft mlx
		@echo "\033[35m-= Making Cub3D... =-"
		${CC} ${CFLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}
		@echo "\033[32m   ______      __   _____ ____  "
		@echo "\033[32m  / ____/_  __/ /_ |__  // __ \ "
		@echo "\033[32m / /   / / / / __ \ /_ </ / / / "
		@echo "\033[32m/ /___/ /_/ / /_/ /__/ / /_/ /  "
		@echo "\033[32m\____/\__,_/_.___/____/_____/   usage: ./Cub3D <map.cub> [--save]"

mlx:
	@echo "\033[34m-= Making mlx... =-"
	@make -C $(MLX_DIR)
	@echo "\033[34m-= mlx Done ! =-"

ft:
	@echo "\033[33m-= Making Libft... =-"
	@make bonus -C libft
	@echo "\033[33m-= Libft Done ! =-"

bonus:
	rm -f ${OBJS} ${NAME}
	@make ${MKBONUS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	@echo "\033[33m-= Cleaning Libft... =-"
	@make fclean -C libft
	@echo "\033[34m-= Cleaning mlx... =-"
	@make clean -C $(MLX_DIR)
	@echo "\033[35m-= Cleaning Cub3D... =-"
	rm -f ${NAME}
	@echo "Done.\033[0;0m"

re: fclean all

.PHONY: all clean fclean re bonus mlx ft