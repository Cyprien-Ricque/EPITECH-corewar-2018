/*
** EPITECH PROJECT, 2019
** ld
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes 2 parameters, the first is an index or
//an indirect or a direct or a register and the third is a register

char check_ld(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 == NULL || cur->arg3 != NULL)
        return (FAILURE);
    if (check_index(cur->arg1) == false &&
        check_register(cur->arg1) == false &&
        check_direct(cur->arg1) == false &&
        check_indirect(cur->arg1) == false)
        return (FAILURE);
    else if (check_register(cur->arg2) == false)
        return (FAILURE);
    return (SUCCESS);
}
