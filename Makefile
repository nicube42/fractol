PATH_SRC =			./srcs/
PATH_LIBFT =		./libft_printf/
PATH_MLX =			./mlx/
PATH_OBJS =			./objs/

MLX = $(PATH_MLX)libmlx.a
LIBFT = $(PATH_LIBFT)libftprintf.a
NAME = fractol

FILES = $(PATH_SRC)ft_burning_ship.c $(PATH_SRC)ft_calculate_and_print.c $(PATH_SRC)ft_error.c $(PATH_SRC)ft_fractol.c $(PATH_SRC)ft_hooks.c\
		$(PATH_SRC)ft_julia.c $(PATH_SRC)ft_mandelbrot.c $(PATH_SRC)ft_text.c
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(MAKE) -C $(PATH_MLX)
	@$(MAKE) -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MLX)
	make fclean -C $(PATH_LIBFT)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

norme: 
	norminette $(PATH_SRC) $(PATH_LIBFT) ./includes

.PHONY: re all fclean clean norme