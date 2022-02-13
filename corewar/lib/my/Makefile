##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	error_zero.c	\
		gnl.c	\
		m_getnb.c	\
		m_retbase.c	\
		m_revs.c	\
		m_scat.c	\
		m_slen.c	\
		my_atoi.c	\
		my_is_alphanum.c	\
		my_puts.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_strlen.c	\
		m_arraylen.c	\
		m_arrays.c	\
		m_printf.c	\
		p_flag.c	\
		p_iflag.c	\
		my_puts_fd.c

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
