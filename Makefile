
NAME = so_long

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR), main.c key.c maps.c \
	layer.c player.c move_player.c items.c maps_pars.c)
OBJS = ${SRCS:.c=.o}

LIBFT = ./lib/libft.a

MLX = ./lib/minilibx-linux/libmlx.a
MLX_Linux = ./lib/minilibx-linux/libmlx_Linux.a
MINILIBX_FLAGS	= -lm -lXext -lX11
CC = gcc

FLAGS = -Wall -Wextra -Werror

VALGRIND		= valgrind --leak-check=full
#--leak-check=full --show-leak-kinds=all \
#--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

all: $(NAME)

%.o: %.c
	@$(CC) ${FLAGS} ${MINILIBX_FLAGS} -o $@ -c $?

$(NAME): ${LIBFT} $(NAME) $(OBJS) ${MLX} ${MLX_Linux}
	${CC} ${FLAGS} ${SRCS} -o $(NAME) ${LIBFT} ${MLX} ${MLX_Linux} ${MINILIBX_FLAGS}

${MLX}:
	make all -C lib/minilibx-linux

${LIBFT}:
	make all -C lib

clean:
	-rm -f ${OBSJ}
	make clean -C lib
	make clean -C lib/minilibx-linux

fclean: clean
	-rm -f $(NAME)
	make fclean -C lib
re: fclean all
	make re -C lib

test:
	${VALGRIND}	./so_long

.PHONY: printf
