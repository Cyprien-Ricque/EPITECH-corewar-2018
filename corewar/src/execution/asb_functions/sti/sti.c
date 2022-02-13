/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <zconf.h>
#include "corewar.h"
#include "lib.h"

void fill_mem(corewar_t *crw, int pos, char *str)
{
    while (m_slen(str) != 8)
        str = m_scat("0", str, 1, 0);
    for (int i = 0; i < 4; ++i) {
        crw->map[((pos + 3 - i) % MEM_SIZE < 0) ?
            ((pos + 3 - i) % MEM_SIZE) + MEM_SIZE :
            (pos + 3 - i) % MEM_SIZE] = (unsigned char)(
            (str[m_slen(str) - 2 - i * 2] - '0') * 16 +
            str[m_slen(str) - 1 - i * 2] - '0');
    }
}

bool sti_check(corewar_t *crw, fct_t *fct)
{
    if (fct->valid == false || (fct->params[0].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[0].value)) ||
        (fct->params[1].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[1].value)) ||
        (fct->params[2].size == REGISTER_SIZE &&
        !get_regv(crw, fct->params[2].value)))
        return (false);
    return (true);
}

char sti_f(corewar_t *crw, fct_t *fct)
{
    int pos;
    char *str;

    if (sti_check(crw, fct) == false)
        return FAILURE;
    pos = crw->tmp->pc + ((fct->params[1].size == REGISTER_SIZE ?
        *get_regv(crw, fct->params[1].value) :
        octect_to_dec(fct->params[1].value, fct->params[1].size)) +
        (fct->params[2].size == REGISTER_SIZE ?
        *get_regv(crw, fct->params[2].value) :
        octect_to_dec(fct->params[2].value, fct->params[2].size))) %
        IDX_MOD;
    str = m_retbase_o(*get_regv(crw, fct->params[0].value), 16);
    if (!str)
        return (FAILURE);
    fill_mem(crw, pos, str);
    crw->tmp->pc += 2 + fct->params[0].size + fct->params[1].size;
    crw->tmp->pc += fct->params[2].size;
    return (SUCCESS);
}