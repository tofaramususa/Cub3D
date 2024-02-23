NAME = cub3D

SRCS = main.c 02_raycast.c 

OBJ = $(SRCS:.c=.o)

CC = gcc

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER = cub3D.h

START = cd minilibx-linux && make

all: $(NAME)

$(NAME):$(OBJ)
		$(START)
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