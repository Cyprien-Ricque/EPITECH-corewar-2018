/*
** EPITECH PROJECT, 2019
** missing_params
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

const char nb_params[16] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

char check_missing_params(main_t *current, errors_t *errros UNUSED)
{
    char nb = -1;

    if (current->command < 0)
        return (SUCCESS);
    if (!current->arg1)
        nb = 0;
    if (current->arg1 && !current->arg2)
        nb = 1;
    if (current->arg1 && current->arg2 && !current->arg3)
        nb = 2;
    if (current->arg1 && current->arg2 && current->arg3 && !current->arg4)
        nb = 3;
    if (current->arg1 && current->arg2 && current->arg3 && current->arg4)
        nb = 4;
    if (nb_params[(int)current->command] != nb)
        return (FAILURE);
    return (SUCCESS);
}
