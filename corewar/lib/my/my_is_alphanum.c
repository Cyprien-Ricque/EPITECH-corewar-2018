/*
** EPITECH PROJECT, 2019
** my_is_alphanum
** File description:
** my_str_is_alphanum
*/

#include "lib.h"

char my_str_is_num_pos(char const *str)
{
    for (int a = 0; str[a]; ++a) {
        if ((str[a] > '9' || str[a] < '0'))
            return (FALSE);
    }
    return (TRUE);
}