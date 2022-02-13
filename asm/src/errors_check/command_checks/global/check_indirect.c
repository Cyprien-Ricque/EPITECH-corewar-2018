/*
** EPITECH PROJECT, 2019
** check_indirect
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

bool str_in_str(char const *str, char const *check)
{
    bool status;

    for (int a = 0; str[a]; ++a) {
        status = false;
        for (int b = 0; check[b]; ++b) {
            if (str[a] == check[b])
                status = true;
        }
        if (status == false)
            return (false);
    }
    return (true);
}

bool check_indirect(char const *str)
{
    if (str[0] && str[0] == ':' && str[1]) {
        if (str_in_str(str + 1, LABEL_CHARS) == false)
            return (false);
        return (true);
    }
    if (str[0] != '-') {
        for (int a = 0; str[a]; ++a) {
            if (str[a] < '0' || str[a] > '9')
                return (false);
        }
    } else {
        for (int a = 1; str[a]; ++a) {
            if (str[a] < '0' || str[a] > '9')
                return (false);
        }
    }
    return (true);
}
