##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/backtracking.c	\
		src/solver.c \
		src/init_maze.c \
		src/get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) -Wall -Wextra $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all