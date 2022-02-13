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

char *get_map_str(char *str, int pos, int size, int max)
{
    char *news = malloc((size_t)size);

    if (!news)
        return (NULL);
    for (int i = 0; i < size; ++i) {
        if (pos >= max)
            pos = 0;
        news[i] = str[pos];
        ++pos;
    }
    return (news);
}

char init_execution(corewar_t *crw)
{
    crw->cycle = 0;
    crw->cycle_to_die = CYCLE_TO_DIE;
    crw->live_done = 0;
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        crw->tmp->cycle_live = malloc(8);
        if (!crw->tmp->cycle_live)
            return (FAILURE);
        *crw->tmp->cycle_live = 0;
        crw->tmp->pc = crw->tmp->load_address;
        crw->tmp->carry = 0;
        crw->tmp->wait = -1;
        crw->tmp->origin = true;
        crw->tmp->prog_nb = crw->tmp->registers[0];
    }
    return (SUCCESS);
}

bool progs_are_alive(corewar_t *crw)
{
    int ct = 0;

    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        if (*crw->tmp->cycle_live && crw->tmp->origin == true) {
            ++ct;
            *crw->tmp->cycle_live = 0;
        } else if (!*crw->tmp->cycle_live && crw->tmp->origin == true)
            *crw->tmp->cycle_live = -1;
    }
    if (ct > 1)
        return (true);
    return (false);
}

char wait(corewar_t *crw, fct_t *fct)
{
    if (crw->tmp->wait == -2) {
        crw->tmp->wait = -1;
        return (FAILURE);
    }
    if (crw->tmp->wait == -1)
        crw->tmp->wait = op_tab[fct->function - 1].nbr_cycles - 1;
    if (!crw->tmp->wait) {
        crw->tmp->wait = -1;
        return (SUCCESS);
    }
    --crw->tmp->wait;
    return (FAILURE);
}