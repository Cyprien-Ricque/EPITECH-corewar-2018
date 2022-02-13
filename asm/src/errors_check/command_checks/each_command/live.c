/*
** EPITECH PROJECT, 2019
** live
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char check_live(main_t *current, errors_t *errors UNUSED)
{
    if (current->arg1 == NULL || current->arg2 != NULL)
        return (FAILURE);
    if (check_direct(current->arg1) == false)
        return (FAILURE);
    return (SUCCESS);
}