/*
** EPITECH PROJECT, 2019
** my_puts
** File description:
** my_puts
*/

#include "lib.h"
#include <unistd.h>

void my_puts(char const *str)
{
    if (str == NULL)
        return;
    write(1, str, (size_t)my_strlen(str));
}