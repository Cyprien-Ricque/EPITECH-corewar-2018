/*
** EPITECH PROJECT, 2019
** alone_arguments
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char check_args_alone(main_t *current, errors_t *errors UNUSED)
{
    if (current->command < 0 && (current->arg1 != NULL || current->arg2 != NULL
        || current->arg3 != NULL || current->arg4 != NULL))
        return (FAILURE);
    return (SUCCESS);
}
