/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "lib.h"

char live_f(corewar_t *crw, fct_t *fct)
{
    crw->live_done++;
    for (proc_t *tmp = crw->procs_head; tmp; tmp = tmp->next) {
        if (tmp->prog_nb ==
            octect_to_dec(fct->params[0].value, fct->params[0].size)) {
            m_printf(1, "Le joueur %d (%s) est en vie\n",
                crw->tmp->prog_nb, crw->tmp->name);
            break;
        }
    }
    *crw->tmp->cycle_live = 1;
    crw->tmp->pc += 5;
    return (SUCCESS);
}