NAME:= cub3D 

SRCS =  main.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -Iinclude

HEADER = cub3d.h

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean