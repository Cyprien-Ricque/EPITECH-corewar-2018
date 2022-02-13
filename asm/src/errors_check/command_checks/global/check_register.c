/*
** EPITECH PROJECT, 2019
** check_register
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

bool check_register(char const *str)
{
    if (!str[0] || str[0] != 'r' || !str[1])
        return (false);
    for (int a = 1; str[a]; ++a) {
        if (str[a] < '0' || str[a] > '9')
            return (false);
    }
    if (my_atoi(str + 1) <= 0 || my_atoi(str + 1) > 16)
        return (false);
    return (true);
}
