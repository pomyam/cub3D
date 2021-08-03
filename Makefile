NAME = cub3D

SRCS = srcs/ft_analyse_map.c srcs/ft_analyse_cycle.c srcs/ft_bmp.c \
		srcs/ft_lodev.c srcs/ft_draw_vertical.c srcs/ft_errors.c \
		srcs/ft_hit_side.c srcs/ft_init_map.c srcs/ft_init_parser.c srcs/ft_init_player.c \
		srcs/ft_keys.c srcs/ft_my_mlx.c srcs/ft_player_update.c srcs/ft_raycast.c \
		srcs/ft_split.c srcs/ft_sprite1.c srcs/ft_sprite.c srcs/parser_r.c \
		srcs/main.c srcs/parser.c srcs/parser1.c srcs/parser2.c \
		srcs/get_next_line.c srcs/get_next_line_utils.c

OBJS = ${patsubst %.c,%.o,${SRCS}}

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRAMEWORK_FLAGS = -framework OpenGL -framework Appkit

INLUDES = cubadd/get_next_line/get_next_line.h srcs/cub3D.h

HDR = srcs/cub3D.h cubadd/libft/libft.h cubadd/minilibx/mlx.h

LIBFT = libft.a

LIBFT_DIR = cubadd/libft/

GNL_DIR = cubadd/get_next_line/

MLX = libmlx.a

MLX_DIR = cubadd/minilibx/

IMAGE = something.bmp

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	make -C ${LIBFT_DIR} bonus
	make -C ${MLX_DIR}
	cp ${MLX_DIR}${MLX} ./
	cp ${LIBFT_DIR}${LIBFT} ./
	${CC} ${OBJS} ${LIBFT} ${MLX} ${FRAMEWORK_FLAGS} -o ${NAME}

clean:
	rm -f ${OBJS} ${LIBFT}
	rm -f ${OBJS}
	make -C $(LIBFT_DIR) fclean
	make -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME} ${MLX}
	rm -f ${IMAGE}

re: fclean all

.PHONY: all clean fclean re