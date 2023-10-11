NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LFLAGS		=	-Lget_next_line -Llibft -Lminilibx -lft -lmlx -framework OpenGL -framework AppKit
SOURCES		=	so_long.c utils.c controllers.c map.c images.c visualizer.c validate.c preconditions.c fill_flood.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ			=	$(SOURCES:%.c=%.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	make -C libft
	make -C minilibx
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	make -C libft		fclean
	make -C minilibx	clean
	rm $(OBJ)

fclean : clean
	rm	-f $(NAME)

re		:	fclean all
