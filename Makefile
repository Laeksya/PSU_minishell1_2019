##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile  and its tests
##

NAME	=	mysh
NAME_TESTS = 	test_

SRC	=	main.c 				\
		my_string.c 		\
		display.c

CFLAGS +=	-Wextra -Wall -g3

SRC_TESTS =
OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TESTS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		rm -f *.gcno
		rm -f *.gcda
		rm -f vgcore*
		rm -f *.vscode

re:	fclean all

tests_run: 	$(OBJ_TESTS)
			gcc -o $(NAME_TESTS) $(OBJ_TESTS) --coverage -lcriterion
			./$(NAME_TESTS)

.PHONY:		all clean fclean re