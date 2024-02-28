NAME = cub3D

SRCS = main.c raycast.c texture_functions.c wall_distance.c hooks.c movement.c init_functions.c init_player.c

OBJ = $(SRCS:.c=.o)

CC = cc -fsanitize=address -g3 -fno-omit-frame-pointer

CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER = cub3D.h

START = cd mlx && make

all: $(NAME)

$(NAME):$(OBJ)
		@$(START)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

norm:
	norminette $(SRCS) $(HEADER)

clean:
	cd mlx && make clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean