NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC =	src/main.c \
		src/mlx_utility/mu_draw_rect.c src/mlx_utility/mu_new_img.c src/mlx_utility/mu_new_rect.c \
		src/mlx_utility/mu_new_trgb.c src/mlx_utility/mu_put_pixel.c src/mlx_utility/mu_new_xpm_img.c \
		src/events/key_hook.c src/events/mouse_hook.c \
		src/rendering/cgtutor.c \
		src/vec2/perpendicular_vec2.c src/vec2/s_multiplication.c

INC = -Iinc -Imlx -Ilibft

LMLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX = ./mlx/libmlx.a

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(INC) $(MLX) $(LMLX) $(LIBFT) -o $(NAME)

$(MLX):
	@make -C mlx

$(LIBFT):
	@make -C libft

clean:
	@make clean -C libft

fclean:
	@rm $(NAME)
	@make fclean -C libft
	@make clean -C mlx

re: fclean all

.PHONY: all clean fclean re
