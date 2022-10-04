NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -L./mlx -lmlx -framework AppKit -framework OpenGL -g
SRCS = main.c \
		setupgame.c	\
		preimg1.c	\
		preimg2.c	\
		preimg3.c	\
		utils.c		\
		utils2.c	\
		create_map.c	\
		draw_image.c	\
		move.c			\
		move2.c			\
		error.c			\

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
all: ${LIBFT} ${NAME}

$(MINI):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS) $(MINI) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(LIBFT)

%.o: %.c
	@echo $(R)Complining: [$<]
	@${CC} -c $< -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)
	@make clean -C libft/

fclean: clean
	@rm -rf cub3d
	@make fclean -C libft/

re: fclean all

.PHONY: fclean re all clean