NAME = fractol
SRC = init.c event.c math_utils.c render.c string_utils.c main.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
MLX_DIR = ./minilibx-linux
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean all

.PHONY: clean fclean re all
