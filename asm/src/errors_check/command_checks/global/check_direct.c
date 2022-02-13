/*
** EPITECH PROJECT, 2019
** check_direct
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

bool check_direct_function(char const *str)
{
    if (str[1] != '-') {
        if (str_in_str(str + 1, LABEL_CHARS) == false)
            return (false);
    } else {
        if (str_in_str(str + 2, LABEL_CHARS) == false)
            return (false);
    }
    return (true);
}

bool check_direct(char const *str)
{
    if (str[0] != '%' || str[1] == '\0') {
        return (false);
    } else if (str[1] != ':') {
        if (check_direct_function(str) == false)
            return (false);
    } else {
        if (str_in_str(str + 2, LABEL_CHARS) == false)
            return (false);
    }
    return (true);
}