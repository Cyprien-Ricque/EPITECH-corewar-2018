/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"

static const char byte_value[3][4] = {{1, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}};

char f_aff(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    UNUSED char *byte_code)
{
    if (function->function != 16)
        return 1;
    if (check_byte_code_value(byte_code, byte_value, 1) == false) {
        function->valid = false;
        return 1;
    }
    get_register(&function->params[0], map, i);
    return 0;
}