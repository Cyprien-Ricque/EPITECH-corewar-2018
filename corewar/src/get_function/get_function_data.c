/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"

const char args[16] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

char (*fcts[16])(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code) =
{
    f_live, f_ld, f_st, f_add, f_sub, f_and,
    f_or, f_xor, f_zjump, f_ldi, f_sti,
    f_fork, f_lld, f_lldi, f_lfork, f_aff
};

void get_args_value(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code)
{
    for (int j = 0; j != 16; j++) {
        if (fcts[j](function, map, i, byte_code) == 0)
            break;
    }
}

char nb_args(char function)
{
    int num = 1;

    for (; num < function; num++);
    return args[num -1];
}
