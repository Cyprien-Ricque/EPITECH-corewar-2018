/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <zconf.h>
#include "corewar.h"
#include "lib.h"

char sub_f(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == true && get_regv(crw, fct->params[0].value) &&
        get_regv(crw, fct->params[1].value) &&
        get_regv(crw, fct->params[2].value))
        crw->tmp->registers[*fct->params[2].value - 1] =
        *get_regv(crw, fct->params[0].value) -
        *get_regv(crw, fct->params[1].value);
    else {
        crw->tmp->carry = 0;
        return (FAILURE);
    }
    if (!crw->tmp->registers[*fct->params[2].value - 1])
        crw->tmp->carry = 1;
    else
        crw->tmp->carry = 0;
    crw->tmp->pc +=
        2 + fct->params[0].size + fct->params[1].size + fct->params[2].size;
    return (SUCCESS);
}
