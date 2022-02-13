/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"

static const char byte_value[3][4] = { {1, 0, 0, 0}, { 11, 1, 0, 0},
    {0, 0, 0, 0}};

char f_st(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code)
{
    if (function->function != 3)
        return 1;
    if (check_byte_code_value(byte_code, byte_value, 2) == false) {
        function->valid = false;
        return 1;
    }
    get_register(&function->params[0], map, i);
    (byte_code[1] == 1) ?
        get_register(&function->params[1], map, i) :
        get_indirect(&function->params[1], map, i, T_IND);
    return 0;
}