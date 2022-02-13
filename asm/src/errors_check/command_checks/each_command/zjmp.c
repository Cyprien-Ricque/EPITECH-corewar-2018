/*
** EPITECH PROJECT, 2019
** zjmp
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

//This function takes 1 parameter which is an index

char check_zjmp(main_t *cur, errors_t *errors UNUSED)
{
    if (cur->arg1 == NULL || cur->arg2 != NULL)
        return (FAILURE);
    if (check_direct(cur->arg1) == false &&
        check_index(cur->arg1) == false)
        return (FAILURE);
    return (SUCCESS);
}
