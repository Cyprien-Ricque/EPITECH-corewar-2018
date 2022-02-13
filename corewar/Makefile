##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Created by Emilien Delevoye
##

CC	=	gcc

I_DIR	=	-I include/ -I lib/my/include

CFLAGS	+=	$(I_DIR)
CFLAGS	+=	-W -Wall -Wextra -g

NAME	=	corewar

SRC	= 	  ./src/corewar.c \
		src/execution/execution_minfct.c	\
		src/execution/get_args_value.c	\
	  ./src/error.c \
	  ./src/execution/asb_functions/add/add.c \
	op.c	\
	  ./src/execution/asb_functions/add/add_f.c \
	  ./src/execution/asb_functions/aff/aff.c \
	  ./src/execution/asb_functions/aff/aff_f.c \
	  ./src/execution/asb_functions/and/and.c \
	src/write_in_arena/find_pos.c	\
	  ./src/execution/asb_functions/and/and_f.c \
	  ./src/execution/asb_functions/fork/fork.c \
	  ./src/execution/asb_functions/fork/fork_f.c \
	  ./src/execution/asb_functions/ld/ld.c \
	  ./src/execution/asb_functions/ld/ld_f.c \
	  ./src/execution/asb_functions/ldi/ldi.c \
	  ./src/execution/asb_functions/ldi/ldi_f.c \
	  ./src/execution/asb_functions/lfork/lfork.c \
	  ./src/execution/asb_functions/lfork/lfork_f.c \
	  ./src/execution/asb_functions/live/live.c \
	  ./src/execution/asb_functions/live/live_f.c \
	  ./src/execution/asb_functions/lld/lld.c \
	  ./src/execution/asb_functions/lld/lld_f.c \
	  ./src/execution/asb_functions/lldi/lldi.c \
	  ./src/execution/asb_functions/lldi/lldi_f.c \
	  ./src/execution/asb_functions/or/or.c \
	  ./src/execution/asb_functions/or/or_f.c \
	  ./src/execution/asb_functions/st/st.c \
	  ./src/execution/asb_functions/st/st_f.c \
	  ./src/execution/asb_functions/sti/sti.c \
	  ./src/execution/asb_functions/sti/sti_f.c \
	  ./src/execution/asb_functions/sub/sub.c \
	  ./src/execution/asb_functions/sub/sub_f.c \
	  ./src/execution/asb_functions/xor/xor.c \
	  ./src/execution/asb_functions/xor/xor_f.c \
	  ./src/execution/asb_functions/zjump/zjump.c \
	  ./src/execution/asb_functions/zjump/zjump_f.c \
	  ./src/execution/execution.c \
	  ./src/get_function/get_args.c \
	  ./src/get_function/get_function.c \
	  ./src/get_function/get_function_args.c \
	  ./src/get_function/get_function_data.c \
	  ./src/main.c \
	  ./src/parsing/new_node.c \
	  ./src/parsing/params.c \
	  ./src/parsing/parse.c \
	  ./src/write_in_arena/invalid_progs_nb.c \
	  ./src/write_in_arena/organize_in_memory.c \
	  ./src/write_in_arena/read_progs.c \
	  ./src/write_in_arena/space_to_write.c \
	  ./src/write_in_arena/write_progs.c \
	  ./src/get_function/check_byte_code.c

OBJ	=	$(SRC:.c=.o)

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

re:		fclean all

