##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/generator.c	\
		src/init_maze.c \
		src/maze_move.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) -Wall -Wextra $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all