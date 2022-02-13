/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

void st_ind(corewar_t *crw, fct_t *fct)
{
    int pos = get_indv(crw, fct->params[1].value, fct->params[1].size);
    char *str;

    if (get_regv(crw, fct->params[0].value)) {
        str = m_retbase_o(*get_regv(crw, fct->params[0].value), 16);
        fill_mem(crw, pos, str);
    }
}

void st_reg(corewar_t *crw, fct_t *fct)
{
    if (get_regv(crw, fct->params[1].value) &&
        get_regv(crw, fct->params[0].value))
        crw->tmp->registers[*fct->params[1].value - 1] = *get_regv(crw,
        fct->params[0].value);
}

char st_f(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == false || (fct->params[1].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[1].value)) ||
        !get_regv(crw, fct->params[0].value)) {
        return (FAILURE);
    }
    if (fct->params[1].size == INDIRECT_SIZE)
        st_ind(crw, fct);
    if (fct->params[1].size == REGISTER_SIZE)
        st_reg(crw, fct);
    crw->tmp->pc += 2 + fct->params[0].size + fct->params[1].size;
    return (SUCCESS);
}