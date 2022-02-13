/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "lib.h"

void new_assignement(corewar_t *crw, proc_t *new_proc)
{
    new_proc->carry = crw->tmp->carry;
    new_proc->load_address = crw->tmp->load_address;
    new_proc->cycle_live = crw->tmp->cycle_live;
    new_proc->carry = crw->tmp->carry;
    new_proc->prog_size = crw->tmp->prog_size;
    new_proc->wait = -2;
    new_proc->origin = false;
    new_proc->prog_nb = crw->tmp->prog_nb;
}

char fork_f(corewar_t *crw, fct_t *fct)
{
    proc_t *new_proc = malloc(sizeof(proc_t));

    if (!new_proc)
        return (FAILURE);
    new_proc->next = crw->tmp->next;
    crw->tmp->next = new_proc;
    new_proc->name = crw->tmp->name;
    new_assignement(crw, new_proc);
    new_proc->pc = get_indv(crw, fct->params[0].value, fct->params[0].size);
    for (int i = 0; i < REG_NUMBER; ++i)
        new_proc->registers[i] = crw->tmp->registers[i];
    crw->tmp->pc += 3;
    return (SUCCESS);
}