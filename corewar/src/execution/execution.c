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

char (*functions[16])(corewar_t *crw, fct_t *fct) =
{
    live_f, ld_f, st_f, add_f, sub_f, and_f, or_f, xor_f, zjump_f, ldi_f,
    sti_f, fork_f, lld_f, lldi_f, lfork_f, aff_f
};

char execution(corewar_t *crw)
{
    fct_t *fct = malloc(sizeof(fct_t));

    if (!fct)
        return (FAILURE);
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        if (*crw->tmp->cycle_live == -1)
            continue;
        crw->tmp->pc %= MEM_SIZE;
        crw->tmp->pc += crw->tmp->pc < 0 ? MEM_SIZE : 0;
        if (get_function(fct, crw->map, crw->tmp->pc) == FAILURE)
            return (FAILURE);
        if (!fct->function)
            ++crw->tmp->pc;
        if (!fct->function || wait(crw, fct) == FAILURE)
            continue;
        if (functions[(int)fct->function - 1](crw, fct) == FAILURE)
            ++crw->tmp->pc;
    }
    return (SUCCESS);
}

void disp_winner(corewar_t *crw)
{
    int ct = 0;

    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
        if (!*crw->tmp->cycle_live && crw->tmp->origin == true)
            ct++;
    if (ct > 1)
        return;
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
        if (!*crw->tmp->cycle_live && crw->tmp->origin == true)
            m_printf(1, "Le joueur %d (%s) a gagné.\n", crw->tmp->prog_nb,
            crw->tmp->name);
}

char main_exec(corewar_t *crw, int cycle)
{
    for (crw->cycle = 1; (crw->cycle < crw->nbr_cycle ||
        crw->nbr_cycle == -1); ++crw->cycle) {
        if (cycle == crw->cycle_to_die && progs_are_alive(crw) == false)
            break;
        if (crw->live_done > NBR_LIVE) {
            crw->cycle_to_die = crw->cycle_to_die - CYCLE_DELTA < 0 ? 0 :
                crw->cycle_to_die - CYCLE_DELTA;
            crw->live_done = 0;
        }
        if (execution(crw) == FAILURE)
            return (FAILURE);
        ++cycle;
        if (cycle > crw->cycle_to_die)
            cycle = 0;
    }
    if (crw->nbr_cycle != -1)
        display_map(crw);
    disp_winner(crw);
    return (SUCCESS);
}

char exec_progs(corewar_t *crw)
{
    int cycle = 0;

    if (init_execution(crw) == FAILURE)
        return (FAILURE);
    if (main_exec(crw, cycle) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}