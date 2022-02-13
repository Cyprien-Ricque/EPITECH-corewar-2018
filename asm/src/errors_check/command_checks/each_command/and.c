/*
** EPITECH PROJECT, 2019
** and
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes 3 parameters, the two firsts can be direct, indirect or
//register and the third is a register

char check_and(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 == NULL ||
        cur->arg3 == NULL || cur->arg4 != NULL)
        return (FAILURE);
    if (check_register(cur->arg1) == false &&
        check_indirect(cur->arg1) == false &&
        check_direct(cur->arg1) == false &&
        check_index(cur->arg1) == false)
        return (FAILURE);
    else if (check_register(cur->arg2) == false &&
        check_indirect(cur->arg2) == false &&
        check_direct(cur->arg2) == false &&
        check_index(cur->arg2) == false)
        return (FAILURE);
    if (check_register(cur->arg3) == false)
        return (FAILURE);
    return (SUCCESS);
}