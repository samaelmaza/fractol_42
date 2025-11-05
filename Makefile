NAME = fractol
SRC = init.c event.c math_utils.c render.c string_utils.c main.c
SRC_BONUS = init.c event.c math_utils.c render_bonus.c string_utils.c main_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo ">>> Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

bonus : $(MLX_LIB) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: clean fclean re rebonus all
