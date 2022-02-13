/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "lib.h"
#include <unistd.h>

char aff_f(corewar_t *crw, fct_t *fct)
{
    if (!get_regv(crw, fct->params[0].value))
        return (FAILURE);
    crw->tmp->pc += 2 + fct->params[0].size;
    write(1, get_regv(crw, fct->params[0].value), 1);
    return (SUCCESS);
}