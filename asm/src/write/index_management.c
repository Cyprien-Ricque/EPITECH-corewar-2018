/*
** EPITECH PROJECT, 2019
** index_management.c
** File description:
** index management
*/

#include "asm.h"

void write_arg3_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;

    if (cu->command == STI) {
        write_sti_arg_3_index(fd, info, pos, cu);
        return;
    }
    lseek(fd, sizeof(info->header) + cu->call_pos + 2, 0);
    dif = pos - cu->call_pos + 2;
    dif = little_to_big_endian_short(dif);
    write(fd, &dif, sizeof(unsigned short));
}

void write_arg2_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;

    if (cu->command == STI) {
        if ((cu->arg2[0] == ':' && cu->arg3[0] == '%' && cu->arg3[1] == ':')
        || (cu->arg2[0] == '%' &&  cu->arg2[1] == ':' && cu->arg3[0] ==
        '%' && cu->arg3[1] == ':'))
            return (write_sti_arg_2_index(fd, info, pos, cu));
    }
    lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
    if (cu->command == XOR || cu->command == OR || cu->command == AND)
        write_xor_or_and_arg2_index(fd, info, pos, cu);
    else {
        if (cu->command == LDI || cu->command == LLDI)
            pos += (cu->arg2[0] == '%' && cu->arg2[1] == ':') ? 1 : 0;
        dif = pos - cu->call_pos + 1;
        dif = little_to_big_endian_short(dif);
        write(fd, &dif, sizeof(unsigned short));
    }
}

void write_arg1_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;

    lseek(fd, sizeof(info->header) + cu->call_pos, 0);
    if (cu->command == LD || cu->command == LLD || cu->command == LIVE) {
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        write_ld_or_live_arg1_index(fd, info, pos, cu);
    } else {
        if (cu->command == LDI || cu->command == LLDI)
            pos = ldi_offset_arg1_index(fd, info, pos, cu);
        if (cu->command == XOR || cu->command == OR || cu->command == AND) {
            if (cu->arg1[0] == '%')
                lseek(fd, sizeof(info->header) + cu->call_pos + 3, 0);
            if (cu->arg1[0] == ':')
                lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        }
        dif = pos - cu->call_pos;
        dif = little_to_big_endian_short(dif);
        write(fd, &dif, sizeof(unsigned short));
    }
}

void fill_index_ref(int fd, head_t *info, const char *str, unsigned short pos)
{
    for (main_t *cu = info->first; cu != NULL; cu = cu->next) {
        if (DIRECT_INDEX_ARG_1)
            write_arg1_index(fd, info, pos, cu);
        if (INDIRECT_INDEX_ARG_1)
            write_arg1_index(fd, info, pos, cu);
        if (DIRECT_INDEX_ARG_2)
            write_arg2_index(fd, info, pos, cu);
        if (INDIRECT_INDEX_ARG_2)
            write_arg2_index(fd, info, pos, cu);
        if (DIRECT_INDEX_ARG_3)
            write_arg3_index(fd, info, pos, cu);
        if (INDIRECT_INDEX_ARG_3)
            write_arg3_index(fd, info, pos, cu);
    }
}

int add_index_ref(int fd, head_t *info)
{
    main_t *cu = info->first;

    while (cu != NULL) {
        if (cu->index != NULL) {
            if (check_index_with_arg(fd, info, cu) == FAILURE)
                return (FAILURE);
        }
        cu = cu->next;
    }
    return (SUCCESS);
}