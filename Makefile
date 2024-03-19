NAME = cub3D
SRCS_DIR = srcs
OBJS_DIR = objs
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Imlx -fsanitize=address
LIB_FLAGS = -L./lib/libft -lft -L./lib/mlx -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I./include -I./lib/libft/include -I./lib/mlx

SRCS =	main.c \
		parsing/parsing.c \
		parsing/print.c \
		parsing/map.c \
		parsing/parsing_helpers.c \
		parsing/parsing_validation.c \
		parsing/map_validation.c \
		parsing/map_error_handling.c \
		parsing/parse_line.c \
		parsing/free_functions.c \
		parsing/stack.c \
		execution/raycast.c \
		execution/hooks.c \
		execution/init_functions.c \
		execution/init_player.c \
		execution/run_game.c \
		execution/wall_distance.c \
		execution/movement.c \
		execution/texture_functions.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

AR = ar -rcs
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/libft
	@make -s -C ./lib/mlx
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	make clean -C ./lib/libft
	@make clean -C ./lib/mlx
	$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -C ./lib/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
