/*
** EPITECH PROJECT, 2019
** strncpy
** File description:
** strncpy
*/

#include <unistd.h>
#include "lib.h"

char my_strcpy_max(char *dest, char const *src, int max, char *error_msg)
{
    dest[0] = '\0';
    for (int a = 0; src[a] && src[a + 1]; ++a) {
        if (a > max - 1) {
            write(2, error_msg, my_strlen(error_msg));
            return (FAILURE);
        }
        dest[a] = src[a];
        dest[a + 1] = '\0';
    }
    return (SUCCESS);
}