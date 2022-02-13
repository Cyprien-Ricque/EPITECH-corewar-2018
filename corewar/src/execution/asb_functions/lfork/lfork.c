/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "lib.h"

char lfork_f(corewar_t *crw, fct_t *fct)
{
    proc_t *new_proc = malloc(sizeof(proc_t));

    if (!new_proc)
        return (FAILURE);
    new_proc->next = crw->tmp->next;
    crw->tmp->next = new_proc;
    new_proc->name = crw->tmp->name;
    new_assignement(crw, new_proc);
    new_proc->pc = get_lindv(crw, fct->params[0].value, fct->params[0].size);
    for (int i = 0; i < REG_NUMBER; ++i)
        new_proc->registers[i] = crw->tmp->registers[i];
    crw->tmp->pc += 3;
    return (SUCCESS);
}