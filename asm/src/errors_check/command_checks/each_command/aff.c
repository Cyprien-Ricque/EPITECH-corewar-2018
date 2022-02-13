/*
** EPITECH PROJECT, 2019
** aff
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes one parameter wich is a register

char check_aff(main_t *current, errors_t *errors UNUSED)
{
    if (current->arg1 == NULL || current->arg2 != NULL)
        return (FAILURE);
    if (check_register(current->arg1) == false)
        return (FAILURE);
    return (SUCCESS);
}
