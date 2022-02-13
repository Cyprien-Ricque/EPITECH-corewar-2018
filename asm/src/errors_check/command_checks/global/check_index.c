/*
** EPITECH PROJECT, 2019
** check_index_param
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

bool check_index(char const *str)
{
    if (!str || my_strlen(str) <= 1)
        return (false);
    if ((str[0] != ':' || str[1] == '\0') &&
        (str[0] != '%' || str[1] != ':' || str[2] == '\0'))
        return (false);
    return (true);
}