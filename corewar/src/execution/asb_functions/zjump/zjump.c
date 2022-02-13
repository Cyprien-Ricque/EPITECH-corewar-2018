/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

char zjump_f(corewar_t *crw, fct_t *fct)
{
    int nb = octect_to_dec(fct->params[0].value, fct->params[0].size);

    if (!crw->tmp->carry)
        return (FAILURE);
    crw->tmp->pc += nb % IDX_MOD;
    return (SUCCESS);
}