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

char nbr_cycle(char **av, int *i, corewar_t *crw)
{
    (*i)++;
    if (!av[*i] || my_str_is_num_pos(av[*i]) == false)
        return (error("Invalid cycle number.\n"));
    else
        crw->nbr_cycle = my_atoi(av[*i]);
    return (SUCCESS);
}

char prog_number(char **av, int *i, corewar_t *crw)
{
    if (crw->procs_head == NULL && init_proc(crw, TRUE) == FAILURE)
        return (FAILURE);
    (*i)++;
    if (!av[*i] || my_str_is_num_pos(av[*i]) == false)
        return (error("Invalid program number.\n"));
    if (crw->tmp->name && init_proc(crw, FALSE) == FAILURE)
        return (FAILURE);
    if (crw->tmp->registers[0] != -1)
        return (error("Invalid Parameter.\n"));
    crw->tmp->registers[0] = (int)my_atoi(av[*i]);
    if (crw->tmp->registers[0] < 1 || crw->tmp->registers[0] > 4)
        return (error(
            "-n argument is invalid.\nEnter a number between 1 and 4.\n"));
    return (SUCCESS);
}

char load_address(char **av, int *i, corewar_t *crw)
{
    if (crw->procs_head == NULL && init_proc(crw, TRUE) == FAILURE)
        return (FAILURE);
    (*i)++;
    if (!av[*i] || my_str_is_num_pos(av[*i]) == false)
        return (error("Invalid address number.\n"));
    if (crw->tmp->name && init_proc(crw, FALSE) == FAILURE)
        return (FAILURE);
    if (crw->tmp->load_address != -1)
        return (error("Invalid Parameter.\n"));
    crw->tmp->load_address = (int)my_atoi(av[*i]);
    return (SUCCESS);
}

char file(char *file, corewar_t *crw)
{
    if (crw->procs_head == NULL && init_proc(crw, TRUE) == FAILURE)
        return (FAILURE);
    if (crw->tmp->name && init_proc(crw, FALSE) == FAILURE)
        return (FAILURE);
    crw->tmp->fd = open(file, O_RDONLY);
    if (crw->tmp->fd == -1)
        return (error("No such file or directory.\n"));
    crw->tmp->name = my_strdup(file);
    if (!crw->tmp->name)
        return (FAILURE);
    return (SUCCESS);
}