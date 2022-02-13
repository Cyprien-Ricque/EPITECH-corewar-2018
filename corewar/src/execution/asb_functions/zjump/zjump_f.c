/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"

char f_zjump(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    UNUSED char *byte_code)
{
    if (function->function != 9)
        return 1;
    get_indirect(&function->params[0], map, i, T_DIR);
    return 0;
}