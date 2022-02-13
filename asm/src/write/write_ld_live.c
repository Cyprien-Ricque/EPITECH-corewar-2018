/*
** EPITECH PROJECT, 2019
** write_ld_live.c
** File description:
** write ld, live cmd arg in file.cor
*/

#include "asm.h"

void compute_ld_arg_1(head_t *info, char *power, main_t *cu, const char *a)
{
    if ((a[0] == '%' && a[1] == ':') || a[0] == ':')
        cu->call_pos = info->header.prog_size;
    if (a[0] == '%')
        compute_cb_with_direct(info, power, cu);
    else if (a[0] == ':' || (a[0] >= '0' && a[0] <= '9') || a[0] == '-')
        compute_cb_with_indirect(info, power, cu);
}

void write_ld_or_live_arg1_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;
    unsigned int i_dif;

    if (cu->command == LIVE) {
        lseek(fd, sizeof(info->header) + cu->call_pos, 0);
        i_dif = pos - cu->call_pos;
        i_dif = little_to_big_endian_int(i_dif);
        write(fd, &i_dif, sizeof(unsigned int));
        return;
    }
    if (cu->arg1[0] != ':') {
        i_dif = pos - cu->call_pos;
        i_dif = little_to_big_endian_int(i_dif);
        write(fd, &i_dif, sizeof(unsigned int));
    } else {
        dif = pos - cu->call_pos;
        dif = little_to_big_endian_short(dif);
        write(fd, &dif, sizeof(unsigned short));
    }
}

void write_live_arg_1(int fd, char *arg)
{
    unsigned int i_arg = 0;

    if (arg[0] == '%' && ((arg[1] >= '0' && arg[1] <= '9') || arg[1] == '-'))
        i_arg = little_to_big_endian_int((unsigned int)my_atoi(&arg[1]));
    else if (arg[0] == '%' && arg[1] ==':')
        i_arg = little_to_big_endian_int((unsigned int)my_atoi(&arg[2]));
    write(fd, &i_arg, sizeof(unsigned int));
}

void write_ld_arg_1(int fd, char *a)
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
}