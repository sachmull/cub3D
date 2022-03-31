NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC =	src/main.c \
		src/mlx_utility/mu_draw_rect.c src/mlx_utility/mu_new_img.c src/mlx_utility/mu_new_rect.c \
		src/mlx_utility/mu_new_trgb.c src/mlx_utility/mu_put_pixel.c src/mlx_utility/mu_new_xpm_img.c \
		src/events/key_hook.c src/events/mouse_hook.c \
		src/rendering/cgtutor.c \
		src/vec2/perpendicular_vec2.c src/vec2/s_multiplication.c	\
		src/parser/check_args.c				\
		src/parser/parsing.c					\
		src/parser/parsing_identifiers.c		\
		src/parser/parsing_map_content.c		\
		src/parser/parsing_map_specs.c			\
		src/parser/parsing_map_utils.c			\
		src/parser/map_mem_alloc.c				\
		src/parser/check_error_identifiers.c	\
		src/parser/check_error_walls_row.c		\
		src/parser/check_error_walls_column.c	\
		src/parser/map_error_handling_1.c		\
		src/parser/get_next_line.c				\
		src/parser/utils.c						\
		src/parser/tex_handling.c				\


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
