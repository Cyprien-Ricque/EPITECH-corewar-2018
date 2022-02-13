/*
** EPITECH PROJECT, 2019
** write_or_xor_and.c
** File description:
** write or, xor, and cmd arg in file.cor
*/

#include "asm.h"

void compute_cb_with_and_arg_1(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if ((a[0] == '%' && a[1] == ':') || a[0] == ':')
        cu->call_pos = info->header.prog_size;
    if (a[0] == '%')
        compute_cb_with_direct(info, power, cu);
    else if (a[0] == ':' || (a[0] >= '0' && a[0] <= '9') || a[0] == '-')
        compute_cb_with_indirect(info, power, cu);
    if (a[0] == 'r')
        compute_cb_with_register(info, power, cu);
}

void write_and_arg_1(int fd, char *a)
{
    unsigned int i_arg = 0;
    unsigned short s_arg = 0;

    if (a[0] == '%') {
        if (a[1] == ':')
            i_arg = little_to_big_endian_int((unsigned int) my_atoi(&a[2]));
        else
            i_arg = little_to_big_endian_int((unsigned int) my_atoi(&a[1]));
        write(fd, &i_arg, sizeof(unsigned int));
    }
    if (a[0] == ':' || (a[0] >= '0' && a[0] <= '9') || a[0] == '-') {
        if (a[0] == ':')
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[1]));
        else
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[0]));
        write(fd, &s_arg, sizeof(unsigned short));
    }
    if (a[0] == 'r')
        write_register(fd, a);
}

void write_xor_or_and_arg2_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;
    unsigned int i_dif;

    if (cu->arg2[0] == '%') {
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        pos += 3;
        i_dif = pos - cu->call_pos + 1;
        i_dif = little_to_big_endian_int(i_dif);
        write(fd, &i_dif, sizeof(unsigned int));
    }
    if (cu->arg2[0] == ':') {
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        pos += 3;
        dif = pos - cu->call_pos + 1;
        dif = little_to_big_endian_short(dif);
        write(fd, &dif, sizeof(unsigned short));
    }
}