/*
** EPITECH PROJECT, 2019
** write_ldi.c
** File description:
** write ldi cmd arg in file.cor
*/

#include "asm.h"

void compute_cb_with_ldi_arg_1(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if ((a[0] == '%' && a[1] == ':') || a[0] == ':')
        cu->call_pos = info->header.prog_size;
    if (a[0] == '%') {
        compute_cb_with_direct(info, power, cu);
        info->header.prog_size -= 2;
    }
    else if (a[0] == ':') {
        compute_cb_with_indirect(info, power, cu);
    }
    if ((a[0] >= '0' && a[0] <= '9') || a[0] == '-')
        compute_cb_with_indirect(info, power, cu);
}

unsigned short ldi_offset_arg1_index(int fd, const head_t *info, unsigned
    short pos, const main_t *cu)
{
    if (cu->arg1[0] == ':' || cu->arg1[1] == ':')
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
    if (cu->arg1[0] == '%' && cu->arg1[1] == ':'
        && cu->arg2[0] == '%' && cu->arg2[1] == ':') {
        lseek(fd, sizeof(info->header) + cu->call_pos - 1, 0);
        pos += 2;
    }
    return (pos);
}

void write_ldi_arg_1(int fd, char *a)
{
    unsigned short s_arg = 0;

    if (a[0] == '%') {
        if (a[1] == ':')
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[2]));
        else
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[1]));
        write(fd, &s_arg, sizeof(unsigned short));
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