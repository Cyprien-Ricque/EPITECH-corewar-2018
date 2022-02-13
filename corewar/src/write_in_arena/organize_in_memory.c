/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void choose_pos(proc_t *proc, corewar_t *crw)
{
    for (int i = 1; i <= 4 && proc->registers[0] == -1; ++i)
        for (proc_t *tmp = crw->procs_head; tmp; tmp = tmp->next) {
            if (tmp->registers[0] == i)
                break;
            if (!tmp->next)
                proc->registers[0] = i;
        }
}

proc_t *order(corewar_t *crw)
{
    proc_t *new_chain[5] = {NULL, NULL, NULL, NULL, NULL};

    for (int i = 1; i <= 4; ++i)
        for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
            if (crw->tmp->registers[0] == i)
                new_chain[i - 1] = crw->tmp;
    for (int i = 0; new_chain[i]; ++i)
        new_chain[i]->next = new_chain[i + 1];
    return (new_chain[0]);
}

char organize_progs(corewar_t *crw)
{
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        if (crw->tmp->registers[0] == -1)
            choose_pos(crw->tmp, crw);
    }
    crw->procs_head = order(crw);
    return (SUCCESS);
}

bool find_pos(int pos[5][2], int save[5][2])
{
    int space;
    int size;
    bool ok = true;

    for (size = 0; pos[size][0] != -2; ++size);
    space = MEM_SIZE / size;
    for (int j = 0; j < space - 1; j += 20) {
        ok = new_pos(pos, save, space, j);
        if (ok == true)
            break;
    }
    return (ok);
}