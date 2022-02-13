/*
** EPITECH PROJECT, 2019
** st
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes 2 parameters, the first is a register and the second
//which is a register or a number

char check_st(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 == NULL || cur->arg3 != NULL)
        return (FAILURE);
    if (check_register(cur->arg1) == false)
        return (FAILURE);
    if (check_register(cur->arg2) == false &&
        check_indirect(cur->arg2) == false)
        return (FAILURE);
    return (SUCCESS);
}
