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

char invalid_prog_number(corewar_t *crw)
{
    int i = 0;

    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
        ++i;
    if (i <= 1) {
        write(2, "Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] "
        "[-n prog_nb] prog.cor] ...\n", 82);
        return (FAILURE);
    }
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
        for (proc_t *tmp = crw->tmp->next; tmp; tmp = tmp->next)
            if (crw->tmp->registers[0] != -1 &&
                crw->tmp->registers[0] == tmp->registers[0])
                return (error("double definition of prog_number.\n"));
    return (SUCCESS);
}