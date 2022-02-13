/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include <corewar.h>

void get_register(prm_t *param, unsigned char map[MEM_SIZE], int *i)
{
    int j = 0;
    param->type = T_REG;
    param->size = REGISTER_SIZE;

    for (; j != REGISTER_SIZE; j++, (*i)++) {
        *i %= MEM_SIZE;
        param->value[j] = map[(*i)];
    }
    *i %= MEM_SIZE;
    param->value[j] = -1;
}

void get_direct(prm_t *param, unsigned char map[MEM_SIZE], int *i, char type)
{
    int j = 0;
    param->type = type;
    param->size = DIRECT_SIZE;

    for (; j != DIRECT_SIZE; j++, (*i)++) {
        *i %= MEM_SIZE;
        param->value[j] = map[(*i)];
    }
    *i %= MEM_SIZE;
    param->value[j] = -1;
}

void get_indirect(prm_t *param, unsigned char map[MEM_SIZE], int *i, char type)
{
    int j = 0;
    param->type = type;
    param->size = INDIRECT_SIZE;

    for (; j != INDIRECT_SIZE; j++, (*i)++) {
        *i %= MEM_SIZE;
        param->value[j] = map[(*i)];
    }
    *i %= MEM_SIZE;
    param->value[j] = -1;
}