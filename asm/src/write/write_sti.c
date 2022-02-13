/*
** EPITECH PROJECT, 2019
** write_sti.c
** File description:
** write sti cmd arg in file.cor
*/

#include "asm.h"

void compute_cb_with_sti_arg3(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if (a[0] == '%') {
        if (a[1] == ':')
            cu->call_pos = info->header.prog_size;
        compute_cb_with_direct(info, power, cu);
        info->header.prog_size -= 2;
    }
    if (a[0] == 'r')
        compute_cb_with_register(info, power, cu);
}

void compute_cb_with_sti_arg_2(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if ((a[0] == '%' && a[1] == ':') || a[0] == ':')
        cu->call_pos = info->header.prog_size;
    if (a[0] == '%') {
        compute_cb_with_direct(info, power, cu);
        info->header.prog_size -= 2;
    } else if (a[0] == ':' || (a[0] >= '0' && a[0] <= '9') || a[0] == '-') {
        compute_cb_with_indirect(info, power, cu);
    }
    if (a[0] == 'r')
        compute_cb_with_register(info, power, cu);
}

void write_sti_arg3(int fd, char *a)
{
    unsigned short s_arg = 0;
    unsigned char c_arg = 0;

    if (a[0] == '%') {
        if (a[1] == ':')
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[2]));
        else
            s_arg = little_to_big_endian_short((unsigned short) my_atoi(&a[1]));
        write(fd, &s_arg, sizeof(unsigned short));
    }
    if (a[0] == 'r') {
        c_arg = (unsigned char)my_atoi(&a[1]);
        write(fd, &c_arg, sizeof(unsigned char));
    }
}

void write_sti_arg_3_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;

    lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
    if (cu->arg3[0] == '%') {
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        dif = pos - cu->call_pos + 3;
    } else if (cu->arg3[0] == ':') {
        lseek(fd, sizeof(info->header) + cu->call_pos + 1, 0);
        dif = pos - cu->call_pos + 3;
    } else {
        lseek(fd, sizeof(info->header) + cu->call_pos, 0);
        dif = pos - cu->call_pos + 1;
    }
    dif = little_to_big_endian_short(dif);
    write(fd, &dif, sizeof(unsigned short));
}

void write_sti_arg_2_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu)
{
    unsigned short dif;

    lseek(fd, sizeof(info->header) + cu->call_pos - 1, 0);
    dif = pos - cu->call_pos + 3;
    dif = little_to_big_endian_short(dif);
    write(fd, &dif, sizeof(unsigned short));
}