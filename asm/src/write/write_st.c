/*
** EPITECH PROJECT, 2019
** write_st.c
** File description:
** write st cmd arg in file.cor
*/

#include "asm.h"

void compute_cb_with_st_arg2(head_t *info, char *power, main_t *cu,
    const char *a)
{
    if (a[0] == ':') {
        cu->call_pos = info->header.prog_size;
        compute_cb_with_indirect(info, power, cu);
    }
    if ((a[0] >= '0' && a[0] <= '9') || a[0] == '-')
        compute_cb_with_indirect(info, power, cu);
    else if (a[0] == 'r')
        compute_cb_with_register(info, power, cu);
}

void write_st_arg2(int fd, char *a)
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