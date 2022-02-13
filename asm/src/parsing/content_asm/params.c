/*
** EPITECH PROJECT, 2019
** params
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char params_check(main_t *current, char *str)
{
    char **params = my_str_to_array(str);

    if ((my_arraylen(params) > 4 || my_arraylen(params) < 0) && str[0] != '\0')
        return (FAILURE);
    if (params && params[0])
        current->arg1 = params[0];
    if (params && params[1])
        current->arg2 = params[1];
    else
        return (SUCCESS);
    if (params[2])
        current->arg3 = params[2];
    else
        return (SUCCESS);
    if (params[3])
        current->arg4 = params[3];
    else
        return (SUCCESS);
    return (SUCCESS);
}