/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

void lld_index(corewar_t *crw, fct_t *fct)
{
    int pos = get_lindv(crw, fct->params[0].value, fct->params[0].size);
    char *str = get_map_str((char *)crw->map, pos, 4, MEM_SIZE);

    if (!str)
        return;
    crw->tmp->registers[*fct->params[1].value - 1] = octect_to_dec(str, 4);
}

void lld_direct(corewar_t *crw, fct_t *fct)
{
    crw->tmp->registers[*fct->params[1].value - 1] = octect_to_dec(
        fct->params[0].value, fct->params[0].size);
}

char lld_f(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == false || !get_regv(crw, fct->params[1].value)) {
        crw->tmp->carry = 0;
        return (FAILURE);
    }
    if (fct->params[0].size == INDIRECT_SIZE)
        lld_index(crw, fct);
    else
        lld_direct(crw, fct);
    if (!crw->tmp->registers[*fct->params[1].value - 1])
        crw->tmp->carry = 1;
    else
        crw->tmp->carry = 0;
    crw->tmp->pc += 2 + fct->params[0].size + fct->params[1].size;
    return (SUCCESS);
}