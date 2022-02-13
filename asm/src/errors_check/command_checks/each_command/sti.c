/*
** EPITECH PROJECT, 2019
** sti
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes 3 parameters, the first parameter is a register and the
//two others are indexes or registers

char check_sti(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 == NULL || cur->arg3 == NULL ||
        cur->arg4 != NULL)
        return (FAILURE);
    if (check_register(cur->arg1) == false)
        return (FAILURE);
    if (check_direct(cur->arg2) == false &&
        check_index(cur->arg2) == false &&
        check_register(cur->arg2) == false &&
        check_indirect(cur->arg2) == false)
        return (FAILURE);
    if (check_direct(cur->arg3) == false &&
        check_index(cur->arg3) == false &&
        check_register(cur->arg3) == false &&
        check_indirect(cur->arg2) == false)
        return (FAILURE);
    return (SUCCESS);
}
