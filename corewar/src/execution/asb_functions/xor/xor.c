/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

void calc_xor(corewar_t *crw, fct_t *fct)
{
    crw->tmp->registers[*fct->params[2].value - 1] =
        (fct->params[0].size == REGISTER_SIZE ?
        crw->tmp->registers[*fct->params[0].value - 1] :
        octect_to_dec(fct->params[0].value, fct->params[0].size)) ^
        (fct->params[1].size == REGISTER_SIZE ?
        crw->tmp->registers[*fct->params[1].value - 1] :
        octect_to_dec(fct->params[1].value, fct->params[1].size));
}

char xor_f(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == false || !get_regv(crw, fct->params[2].value) ||
        (fct->params[0].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[0].value)) ||
        (fct->params[1].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[1].value))) {
        crw->tmp->carry = 0;
        return (FAILURE);
    }
    calc_xor(crw, fct);
    if (!crw->tmp->registers[*fct->params[2].value - 1])
        crw->tmp->carry = 1;
    else
        crw->tmp->carry = 0;
    crw->tmp->pc +=
        2 + fct->params[0].size + fct->params[1].size + fct->params[2].size;
    return (SUCCESS);
}