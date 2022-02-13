/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

char corewar(char **av)
{
    corewar_t crw;

    if (parse(av, &crw) == FAILURE)
        return (FAILURE);
    if (write_progs(&crw) == FAILURE)
        return (FAILURE);
    if (exec_progs(&crw) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}