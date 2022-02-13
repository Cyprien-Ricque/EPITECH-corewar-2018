/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

char checkldi(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == false || (fct->params[0].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[0].value)) ||
        (fct->params[1].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[1].value)) ||
        (fct->params[2].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[2].value))) {
        crw->tmp->carry = 0;
        return (FAILURE);
    }
    return (SUCCESS);
}

void pv_carry_evldi(corewar_t *crw, fct_t *fct, char *str2)
{
    crw->tmp->registers[*fct->params[2].value - 1] = octect_to_dec(str2, 4);
    crw->tmp->pc +=
        2 + fct->params[0].size + fct->params[1].size + fct->params[2].size;
    if (!crw->tmp->registers[*fct->params[2].value - 1])
        crw->tmp->carry = 1;
    else
        crw->tmp->carry = 0;
}

char ldi_f(corewar_t *crw, fct_t *fct)
{
    char *str = get_map_str((char *)crw->map,
        get_indv(crw, fct->params[0].value, fct->params[0].size), 2, MEM_SIZE);
    char *str2;

    if (checkldi(crw, fct) == FAILURE || !str)
        return (FAILURE);
    str2 = get_map_str((char *)crw->map, crw->tmp->pc +
        (octect_to_dec(str, 2) +
        octect_to_dec(fct->params[1].value, fct->params[1].size)) %
        IDX_MOD, 4, MEM_SIZE);
    if (!str2)
        return (FAILURE);
    pv_carry_evldi(crw, fct, str2);
    return (SUCCESS);
}