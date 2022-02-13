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

char assignement(char **av, int *i, corewar_t *crw)
{
    if (my_strcmp(av[*i], "-dump") == true)
        return (nbr_cycle(av, i, crw));
    if (my_strcmp(av[*i], "-n") == true)
        return (prog_number(av, i, crw));
    if (my_strcmp(av[*i], "-a") == true)
        return (load_address(av, i, crw));
    return (file(av[*i], crw));
}

char parse(char **av, corewar_t *crw)
{
    crw->nbr_cycle = -1;
    crw->procs_head = NULL;
    for (int i = 1; av[i]; ++i) {
        if (assignement(av, &i, crw) == FAILURE)
            return (FAILURE);
    }
    if (!crw->tmp->name)
        return (error("Invalid Argument.\n"));
    return (SUCCESS);
}