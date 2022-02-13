/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "lib.h"

char node_assignement(corewar_t *crw)
{
    crw->tmp->next = NULL;
    crw->tmp->name = NULL;
    crw->tmp->carry = 0;
    crw->tmp->load_address = -1;
    crw->tmp->pc = -1;
    for (int i = 0; i < REG_NUMBER; ++i)
        crw->tmp->registers[i] = 0;
    crw->tmp->registers[0] = -1;
    return (SUCCESS);
}

char init_proc(corewar_t *crw, char first)
{
    if (first) {
        crw->procs_head = malloc(sizeof(proc_t));
        if (!crw->procs_head)
            return (FAILURE);
        crw->tmp = crw->procs_head;
    } else {
        if (!crw->tmp->name)
            return (error("Invalid option.\n"));
        crw->tmp->next = malloc(sizeof(proc_t));
        if (!crw->tmp->next)
            return (FAILURE);
        crw->tmp = crw->tmp->next;
    }
    return (node_assignement(crw));
}