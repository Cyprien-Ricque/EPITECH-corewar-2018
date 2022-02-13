/*
** EPITECH PROJECT, 2019
** write_argument.c
** File description:
** write argument function for asm
*/

#include "asm.h"

void write_argument_1(int fd, char cmd, char *arg)
{
    if (cmd == LIVE)
        write_live_arg_1(fd, arg);
    if (cmd == LD || cmd == LLD)
        write_ld_arg_1(fd, arg);
    if (cmd == ST || cmd == ADD || cmd == SUB
        || cmd == AFF || cmd == STI)
        write_register(fd, arg);
    if (cmd == AND || cmd == OR || cmd == XOR)
        write_and_arg_1(fd, arg);
    if (cmd == ZJUMP || cmd == FORK || cmd == LFORK)
        write_zjump_arg_1(fd, arg);
    if (cmd == LDI || cmd == LLDI)
        write_ldi_arg_1(fd, arg);
}

void write_argument_2(int fd, char cmd, char *arg)
{
    if (cmd == LD || cmd == LLD || cmd == ADD || cmd == SUB)
        write_register(fd, arg);
    if (cmd == ST)
        write_st_arg2(fd, arg);
    if (cmd == AND || cmd == OR || cmd == XOR)
        write_and_arg_1(fd, arg);
    if (cmd == LDI || cmd == LLDI)
        write_ldi_arg_1(fd, arg);
    if (cmd == STI)
        write_ldi_arg_1(fd, arg);
}

void write_argument_3(int fd, char cmd, char *arg)
{
    if (cmd == ADD || cmd == SUB || cmd == AND
        || cmd == OR || cmd == XOR || cmd == LDI || cmd == LLDI)
        write_register(fd, arg);
    if (cmd == STI)
        write_sti_arg3(fd, arg);
}