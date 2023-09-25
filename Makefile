NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Lget_next_line -Llibft -Lminilibx -lft -lmlx -framework OpenGL -framework AppKit
SOURCES	=	so_long.c images.c controllers.c map.c visualizer.c validate.c preconditions.c fill_flood.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all		:	$(NAME)

$(NAME)	:	mdir
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

mdir	:
		make -C libft
		make -C minilibx

clean	:
		make -C libft 		clean
		make -C minilibx	clean

fclean : clean
		rm	-f $(NAME)

re		:	fclean all

.PHONY	:	all $(NAME) mdir clean fclean re
