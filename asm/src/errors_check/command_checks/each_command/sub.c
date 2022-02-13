/*
** EPITECH PROJECT, 2019
** sub
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes two parameters, the first can be a direct or an indirect
//the second is a register

char check_sub(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 == NULL || cur->arg3 == NULL
        || cur->arg4 != NULL)
        return (FAILURE);
    if (check_register(cur->arg1) == false)
        return (FAILURE);
    if (check_register(cur->arg2) == false)
        return (FAILURE);
    if (check_register(cur->arg3) == false)
        return (FAILURE);
    return (SUCCESS);
}
