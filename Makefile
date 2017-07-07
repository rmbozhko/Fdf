NAME = fdf
CC = gcc

SRC_C = fdf_creating_field.c fdf.c fdf_error.c get_next_line.c fdf_drawing_field.c fdf_additional_ft.c fdf_zoom.c fdf_color.c

OBJ = $(SRC_C:.c=.o)
CFLAGS = -c -O3 -Wall -Wextra -Werror
HEADER = fdf.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) -L./libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[0;32mFdf is compiled\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
