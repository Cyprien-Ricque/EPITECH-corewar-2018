##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	get_next_line.c	\
		my_arraylen.c	\
		my_atoi.c	\
		my_clean_str.c	\
		my_puts.c	\
		my_str_to_array.c	\
		my_str_to_array_funct.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncpy.c

NAME	=	libmy.a

CFLAGS	=	-W -Wall -Wextra -I include -g

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:    $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
