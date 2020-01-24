##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile  and its tests
##

CC	=	gcc

NAME	=	mysh
NAME_TESTS = 	test_

SRC	=	my_printf/my_strlen.c		 		\
		my_printf/my_put_nbr.c				\
		my_printf/my_putchar.c				\
		my_printf/my_putstr.c				\
		my_printf/my_putnbr_base.c 			\
		my_printf/my_putnbr_unsigned.c   	\
		my_printf/my_putnbr_base_unsigned.c \
		my_printf/function_for_printf2.c 	\
		my_printf/function_for_printf1.c    \
		my_printf/my_printf.c				\
		main.c 				\
		my_strtools.c		\
		my_builtin.c 		\
		display.c

CFLAGS +=	-Wextra -Wall

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