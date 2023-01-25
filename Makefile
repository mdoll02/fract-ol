NAME	:= fractol
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -O3

SRCS	:=      src/fractol.c  src/process_input.c src/mandelbrot.c src/init.c src/process_image.c src/color.c src/input_tools.c\
				src/color_shift.c src/handel_params.c src/julia.c src/burning_ship.c src/input_tools_2.c


OBJS	:= $(SRCS:.c=.o)

.c.o:
	@ ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

$(NAME): $(OBJS)
	@ echo "\033[1;31mcompiling"
	@ $(MAKE) -C mlx all >/dev/null 2>&1
	@ cp ./mlx/libmlx.a .
	@ echo "\033[1;31m		..."
	@ $(MAKE) -C libft all >/dev/null 2>&1
	@ cp ./libft/libft.a .
	@ echo "\033[1;33m			..."
	@ $(CC) $(CFLAGS) -Ofast -o $(NAME) $(OBJS) libft.a libmlx.a -lm -framework OpenGL -framework AppKit
	@ echo "\033[1;32m				finished compiling."
	@ echo " "
	@ echo "\033[1;34mUse ./fractol to run the progam[0m"

all:		${NAME}


clean:
	@${RM} $(OBJS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean:	clean
	@ ${RM} ${NAME}
	@ make fclean -C ./libft
	@ rm libmlx.a
	@ rm libft.a

re:			fclean all

fract: all
	@ echo " "
	@ make clean

.PHONY:		all clean fclean re
