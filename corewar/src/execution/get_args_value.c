/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include <zconf.h>
#include "corewar.h"
#include "lib.h"

int *get_regv(corewar_t *crw, char *arg)
{
    if (*arg >= 1 && *arg <= REG_NUMBER)
        return (&crw->tmp->registers[*arg - 1]);
    return (NULL);
}

int get_dirv(corewar_t UNUSED *crw, char *arg)
{
    return (octect_to_dec(arg, 4));
}

int get_indv(corewar_t *crw, char *arg, int size)
{
    if (size == REGISTER_SIZE && get_regv(crw, arg))
        return ((crw->tmp->pc + *get_regv(crw, arg) % IDX_MOD) % MEM_SIZE);
    if (size == REGISTER_SIZE && !get_regv(crw, arg))
        return (0);
    return ((crw->tmp->pc + octect_to_dec(arg, size) % IDX_MOD) % MEM_SIZE);
}

int get_lindv(corewar_t *crw, char *arg, int size)
{
    if (size == REGISTER_SIZE && get_regv(crw, arg))
        return ((crw->tmp->pc + *get_regv(crw, arg) % IDX_MOD));
    else if (size == REGISTER_SIZE && !get_regv(crw, arg))
        return (0);
    return ((crw->tmp->pc + octect_to_dec(arg, size) % IDX_MOD));
}