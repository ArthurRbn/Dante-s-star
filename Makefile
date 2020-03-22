##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

all:
	(cd generator; make)
	(cd solver; make )

clean:
	(cd generator; make clean)
	(cd solver; make clean)

fclean:	clean
	(cd generator; make fclean)
	(cd solver; make fclean)

re:	fclean all