/*
** EPITECH PROJECT, 2019
** my_clean_str
** File description:
** my_clean_str
*/

#include "lib.h"

char *my_clean_str_begin(char *str)
{
    while ((str[0] == ' ' || str[0] == '\t') && str[0] != '\0')
        move_str(str, 0);
    return (str);
}

char *my_clean_str(char *str)
{
    while ((str[0] == ' ' || str[0] == '\t') && str[0] != '\0')
        move_str(str, 0);
    for (int a = 0; str[a] != '\0'; ++a) {
        if (str[a] != '\0' && str[a + 1] != '\0' && (str[a] == ' '
            || str[a] == '\t') && (str[a + 1] == ' ' || str[a + 1] == '\t')) {
            move_str(str, a);
            if (a != 0)
                --a;
        }
    }
    remove_spaces_end(str);
    return (str);
}