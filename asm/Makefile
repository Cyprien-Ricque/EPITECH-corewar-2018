##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Created by Emilien Delevoye
##

CC	=	gcc

I_DIR	=	-I include/ -I lib/my/include

CFLAGS	+=	$(I_DIR)
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-g

NAME	=	asm

SRC	=	src/main.c	\
		src/main_asm.c	\
		src/read_file/read_file.c	\
		src/usage/usage.c \
		src/write/write.c	\
		src/parsing/setup_name_comment.c	\
		src/parsing/pars_content_file.c	\
		src/parsing/init_and_create_nodes.c	\
		src/parsing/content_asm/index.c	\
		src/parsing/content_asm/command.c	\
		src/parsing/content_asm/params.c	\
		src/free_chained_list/free_flute_t.c	\
		src/free_chained_list/free_content_t.c	\
		src/errors_check/base_check_errors.c	\
		src/errors_check/alone_arguments.c	\
		src/errors_check/check_valid_arguments.c	\
		src/errors_check/missing_params.c   \
		src/write/header_management.c   \
		src/write/index_management.c    \
		src/write/little_endian_conversion.c    \
		src/write/compute_functions.c   \
		src/write/coding_byte_management.c	\
		src/errors_check/command_checks/global/check_direct.c	\
		src/errors_check/command_checks/global/check_indirect.c	\
		src/errors_check/command_checks/global/check_register.c	\
		src/errors_check/command_checks/global/check_index.c	\
		src/errors_check/command_checks/each_command/add.c	\
		src/errors_check/command_checks/each_command/aff.c	\
		src/errors_check/command_checks/each_command/and.c	\
		src/errors_check/command_checks/each_command/fork.c	\
		src/errors_check/command_checks/each_command/ld.c	\
		src/errors_check/command_checks/each_command/ldi.c	\
		src/errors_check/command_checks/each_command/lfork.c	\
		src/errors_check/command_checks/each_command/live.c	\
		src/errors_check/command_checks/each_command/lld.c	\
		src/errors_check/command_checks/each_command/lldi.c	\
		src/errors_check/command_checks/each_command/or.c	\
		src/errors_check/command_checks/each_command/st.c	\
		src/errors_check/command_checks/each_command/sti.c	\
		src/errors_check/command_checks/each_command/sub.c	\
		src/errors_check/command_checks/each_command/xor.c	\
		src/errors_check/command_checks/each_command/zjmp.c	\
		src/errors_check/check_labels.c	\
		src/errors_check/check_indexes.c \
		src/write/write_sti.c \
		src/write/write_ldi.c   \
		src/write/write_or_xor_and.c \
		src/write/write_ld_live.c   \
		src/write/write_st.c \
		src/write/write_arguments.c

OBJ	=	$(SRC:.c=.o)

SRC_TEST =	src/read_file/read_file.c	\
		src/main_asm.c	\
		src/read_file/read_file.c	\
		src/usage/usage.c \
		src/write/write.c	\
		src/parsing/setup_name_comment.c	\
		src/parsing/pars_content_file.c	\
		src/parsing/init_and_create_nodes.c	\
		src/parsing/content_asm/index.c	\
		src/parsing/content_asm/command.c	\
		src/parsing/content_asm/params.c	\
		src/free_chained_list/free_flute_t.c	\
		src/free_chained_list/free_content_t.c	\
		src/errors_check/base_check_errors.c	\
		src/errors_check/alone_arguments.c	\
		src/errors_check/check_valid_arguments.c	\
		src/errors_check/missing_params.c   \
		src/write/header_management.c   \
		src/write/index_management.c    \
		src/write/little_endian_conversion.c    \
		src/write/compute_functions.c   \
		src/write/coding_byte_management.c	\
		src/errors_check/command_checks/global/check_direct.c	\
		src/errors_check/command_checks/global/check_indirect.c	\
		src/errors_check/command_checks/global/check_register.c	\
		src/errors_check/command_checks/global/check_index.c	\
		src/errors_check/command_checks/each_command/add.c	\
		src/errors_check/command_checks/each_command/aff.c	\
		src/errors_check/command_checks/each_command/and.c	\
		src/errors_check/command_checks/each_command/fork.c	\
		src/errors_check/command_checks/each_command/ld.c	\
		src/errors_check/command_checks/each_command/ldi.c	\
		src/errors_check/command_checks/each_command/lfork.c	\
		src/errors_check/command_checks/each_command/live.c	\
		src/errors_check/command_checks/each_command/lld.c	\
		src/errors_check/command_checks/each_command/lldi.c	\
		src/errors_check/command_checks/each_command/or.c	\
		src/errors_check/command_checks/each_command/st.c	\
		src/errors_check/command_checks/each_command/sti.c	\
		src/errors_check/command_checks/each_command/sub.c	\
		src/errors_check/command_checks/each_command/xor.c	\
		src/errors_check/command_checks/each_command/zjmp.c	\
		src/errors_check/check_labels.c	\
		src/errors_check/check_indexes.c \
		src/write/write_sti.c \
		src/write/write_ldi.c   \
		src/write/write_or_xor_and.c \
		src/write/write_ld_live.c   \
		src/write/write_st.c \
		src/write/write_arguments.c

OBJ_TEST	=	$(SRC_TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:		clean
	make fclean -C lib/my
	rm -f $(NAME)

tests_run:	CFLAGS += --coverage
tests_run:	fclean $(OBJ_TEST)
	make -C lib/my
	gcc $(OBJ_TEST) -o unit_tests -L./lib/my -lmy --coverage -lcriterion
	./unit_tests
	make fclean

re:		fclean all
