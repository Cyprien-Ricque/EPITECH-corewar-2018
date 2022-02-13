/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"

static const char byte_value[3][4] = { {11, 10, 0, 0}, {1, 0, 0, 0},
    {0, 0, 0, 0}};

char f_lld(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code)
{
    if (function->function != 13)
        return 1;
    if (check_byte_code_value(byte_code, byte_value, 2) == false) {
        function->valid = false;
        return 1;
    }
    (byte_code[0] == 10) ?
        get_direct(&function->params[0], map, i, T_DIR) :
        get_indirect(&function->params[0], map, i, T_IND);
    get_register(&function->params[1], map, i);
    return 0;
}