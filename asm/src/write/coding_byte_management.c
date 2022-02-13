/*
** EPITECH PROJECT, 2019
** coding_byte_management.c
** File description:
** coding byte management for the asm
*/

#include "asm.h"

void no_cb_management(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if (a[1] == ':')
        cu->call_pos = info->header.prog_size;
    if (cu->command == LIVE)
        compute_cb_with_direct(info, power, cu);
    else
        compute_cb_with_indirect(info, power, cu);
}

void compute_cb_arg1(head_t *info, char *power, main_t *cu, const char *a)
{
    if (cu->command == LFORK || cu->command == FORK
        || cu->command == LIVE || cu->command == ZJUMP)
        no_cb_management(info, power, cu, a);
    if (cu->command == LD || cu->command == LLD)
        compute_ld_arg_1(info, power, cu, a);
    if (cu->command == ST || cu->command == ADD || cu->command == SUB
        || cu->command == AFF || cu->command == STI)
        compute_cb_with_register(info, power, cu);
    if (cu->command == AND || cu->command == OR || cu->command == XOR)
        compute_cb_with_and_arg_1(info, power, cu, a);
    if (cu->command == LDI || cu->command == LLDI)
        compute_cb_with_ldi_arg_1(info, power, cu, a);
}

void compute_cb_arg2(head_t *info, char *power, main_t *cu, const char *a)
{
    if (cu->command == LD || cu->command == LLD || cu->command == ADD ||
        cu->command == SUB)
        compute_cb_with_register(info, power, cu);
    if (cu->command == ST)
        compute_cb_with_st_arg2(info, power, cu, a);
    if (cu->command == AND || cu->command == OR || cu->command == XOR)
        compute_cb_with_and_arg_1(info, power, cu, a);
    if (cu->command == LDI || cu->command == LLDI)
        compute_cb_with_ldi_arg_1(info, power, cu, a);
    if (cu->command == STI)
        compute_cb_with_sti_arg_2(info, power, cu, a);
}

void compute_cb_arg3(head_t *info, char *power, main_t *cu, const char *a)
{
    if (cu->command == ADD || cu->command == SUB || cu->command == AND
        || cu->command == OR || cu->command == XOR || cu->command == LDI
        || cu->command == LLDI)
        compute_cb_with_register(info, power, cu);
    if (cu->command == STI)
        compute_cb_with_sti_arg3(info, power, cu, a);
}

void compute_coding_byte(head_t *info, main_t *cu, char *power)
{
    compute_cb_arg1(info, power, cu, cu->arg1);
    compute_cb_arg2(info, power, cu, cu->arg2);
    compute_cb_arg3(info, power, cu, cu->arg3);
}