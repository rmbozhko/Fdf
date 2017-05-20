NAME = mlx
CC = gcc

SRC_C = fdf_creating_field.c fdf.c fdf_error.c get_next_line.c fdf_drawing_field.c fdf_additional_ft.c fdf_zoom.c fdf_color.c

OBJ = $(SRC_C:.c=.o)
CFLAGS = -c -O3
HEADER = fdf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L./libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
